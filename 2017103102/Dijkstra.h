
template<typename Graph, typename Weight>
class Dijkstra{
	
private:
    Graph &G;
	int s;//单元最短路径,这是原点
	
	Weight *distTo; //从原点s到每一个点的值 //最短距离是多少,原点距离其他的点
	bool *marked;   //已经找到了,做一个标记
	vector<Edge<Weight>*> from; //最路径中都是从那一个节点过来的

public:	
	Dijkstra(Graph &graph,int s):G(graph){
		
		this->s = s;
		
		distTO = new Weight[G.V()];
		marked = new bool[G.V()];
		for(int i=0 ; i<G.V(); i++){
			distTo[i] = Weight(); //模板函数默认构造函数是0
			marked[i] = false;
			from.push_back(NULL);
		}
		
		//开的是图中顶点的个数
		IndexMinHeap<Weight> ipq(G.V());
		
		//Dijkstra
		//原点s初始化操作
		//原点到原点距离一定为0
		distTo[s] = Weight();
		
		//访问过了,变成true
		marked[s] = true;
		
		//压入索引堆中,距离就是distTo[s]
		ipq.insert(s , distTo[s]);
		
		while( !ipq.isEmpty() ){
			//索引堆中最小的元素
			int v = ipq.extractMinIndex();
			
		    //distTo[V]就是s到v的就的最短距离
			
			marked[v] = true;
			
			//对v这个节点进行松弛操作
			
			//访问v这个节点相应的临边
			typename Graph::adjIterator adj(G, v);
			for(Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next()){
				
				//找到这条边的另一个端点
				int w = e->other(v);
				if(!marked[w]){//没有被访问过 ,这条路径加上权值还要小于现有的
					if( from[w] == NULL || distTo[v] + e->wt() < distTo[w]){
						//具体的松弛操作
						distTo[w] = distTo[v] + e->wt();
						from[w] = e;
						if(ipq.contain(w)){
							ipq.change(w,distTo[w]);
						}
						else{
							ipq.insert(w.distTo[w]);
						}
					}
				}
				
			}		
		}
		
	}
	
	~Dijkstra(){
		delete[] distTo;
		delete[] marked;
	}
		
	Weight shortestPath(int w){
		return distTo[w];
	}
	
	bool hasPathTo(int w){
		return marked[w];
	}
	
	void shortestPath( int w,vector<Edge<Weight>> &vec){
		
		stack<Edge<Weight>*> s;
		Edge<Weight> *e = from[w];
		while(e->v() != e->w()){
			s.push(e);
			e = from[e->v()]
		}
		
		while( !e.empty() ){
			e = s.top();
			vec.push_back( *e );
			s.pop;
		}		
	}
	
	void showPath(int w){
		
		assert( w>=0 && w < G.V() );
		
		vector<Edge<Weight>> vec;
		
		shortestPath(w,vec);
		
		for(int i = 0;i<vec.size() ;i++){
			cout<<vec[i].v()<<" -> ";
			if(i == vec.size()-1){
				cout<<vec[i].w()<<endl;
			}
		}		
	}
	
};