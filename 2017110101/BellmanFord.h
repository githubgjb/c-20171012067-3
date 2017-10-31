
template<typename Graph, typename Weight>
class BellmanFord{

private:
	Graph &G; //图的引用
	int s;    //原点
	Weight* distTo;             //s到i的最短路径
	vector<Edge<Weight>*> from; //最短路径中前一个节点是谁
	bool hasNegativeCycle;      //是否有负权环
		
public:
 
    BellmenFord(Graph &graph,int s):G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		for(int i=0 ; i<G.V() ; i++){
			from.push_back(NULL);
		}
		
		//Bellman-Ford 02:23
	}

    ~BellmenFord(){
		delete[] distTo;
	}
	
	bool negativeCycle(){
		return hasNegativeCycle;
	}
	
	Weight shorttestPathTo(int w){
		assert(w >= 0 && w < G.V() );
		assert(!hasNegativeCycle);
		return distTo[w];
	}
	
	bool hasPathTo(int w){
		assert( w>=0 && w<G.V() );
		return from[w] != NULL;
	}
	
	void shortestPath( int w,vector<Edge<Weight> &vec> ){
		assert( w>=0 && w<G.V() );
		assert( !hasNegativeCycle );
		stack<Edge<Weight>*> s;
		Edge<weight> *e = from[w];
		while(e->v() != this->s){
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);
		while( !e.empty() ){
			e = s.top();
			vec.push_back( *e );
			s.pop();
		}
	}
	
	void showPath(int w){
		assert( w>0 && w<G.V() );
		assert( !hasNegativeCycle );
		
		vector<Edge<Weight>> vec;
		shortestPath(w , vec);
		
		for(int i=0 ; i < vec.size() ;i++){
			cout << vec[i].v() << " -> " ;
			if( i == vec.size()-1 ){
				cout << vec[i].w() << endl;
			}
		}				
	}
};
