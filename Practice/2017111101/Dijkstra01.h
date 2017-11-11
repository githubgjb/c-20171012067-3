

template<typename Graph, typename Weight>
class Dijkstra{

private:
	Graph &G;  //图的引用
	int s;     //原点
	
	Weight *distTo;  //原点s到每一个点的最短距离
	bool *marked;    //已经找到的原点要做标记
	vector<Edge<Weight>*> from;  //具体的最短路径

public:
	
	Dijkstra(Graph &graph, int s):G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		marked = new bool[G.V()];
		for(int i=0 ; i < G.V() ; i++){
			//模板类型默认的构造函数
			//int double都有默认的构造函数
			distTo[i] = Weight();//Weight默认构造函数为0
			marked[i] = false;
			from.push_back(NULL);
		}
		
		IndexMinHeap<Weight> ipq(G.V());
		
		//Dijkstra
		
		//原点到原点一定是0
		distTo[s] = Weight();
		
		//访问过了,标记为true
		marked[s] = true;
		
		//压入到最小索引堆中,键,值
		ipq.insert( s , distTo[s] );
		
		//只要最小索引堆还不为空的话
		while( !ipq.isEmpty() ){
			int v = ipq.extractMinIndex();
					
			//distTo[v]就是s到v的最短距离
			marked[v] = true;
			
			//进行松弛操作  //Relaxation
			typename Graph::adjIterator adj(G , v);
			for(Edge<Weight> * e = adj.begin() ; !adj.end() ; e = adj.next() ){
				//这个边的另一个端点
				int w = e->other(v);
				
				//之前没有mark访问过
				if( !marked[w] ){
					//没有访问过          //新的权值,比原来的小,说明找到了更短的路径
					if( from[w] == NULL || distTo[v] + e->wt() < distTo[w]){
						//找到了,就更新
						distTo[w] = distTo[v] + e->wt();
						
						//从那一个点来的要更新
						from[w] = e;
						
						//维护一下就小索引堆
						if(ipq.contain(w)){
							ipq.change(w,dist[w]);
						}else{
							ipq.insert(w,dist[w]);
						}
						
					}
				}
			
			}
			
		}
			
	}
	
	~Dijkstra(){
		delete[] disTo;
		delete[] marked;
	}
	
	
	//顶点s到其它点w的权值是多少
	Weight shortestPathTo(int w){
		return distTo[w];
	}
	
	//s到w有没有路径
	bool hasPathTo(int w){
		return marked[w];
	}
	
	//获得最短路径
	void shortestPath(int w,vector<Edge<Weight>> &vec){
		
		stack<Edge<Weight>*> s;
		Edge<Weight> *e = from[w];
		while(e->v() != e->w()){
			s.push(e);
			e = from[e->v()];
		}
		
		while( !s.empty() ){
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
		
	}
	
	//显示路径
	void showPath(int w){
		assert(w >= 0 && w < G.V() );
		vector<Edge<Weight>> vec;
		shortestPath(w,vec);
		for(int i = 0; i < vec.size() ; i++){
			cout<<vec[i].v()<<" -> ";
			if( i == vec.size()-1 ){
				cout<<vec[i].w()<<endl;
			}
		}		
	}
		
};