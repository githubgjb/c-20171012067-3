
template<typename Graph, typename Weight>
class Dijkstra{
	
private:
    Graph &G;
	int s;//单元最短路径,这是原点
	
	Weight *distTo; //最短距离是多少,原点距离其他的点
	bool *marked;   //已经找到了,做一个标记
	vector<Edge<Weight>*> from;

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
		//原点05:52
		
		
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