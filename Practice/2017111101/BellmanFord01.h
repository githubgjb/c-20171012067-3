
template<typename Graph,typename Weight>

class BellmanFord{

private:
	Graph &G;
	int s;
	Weight* distTo;
	vector<Edge<Weight>*> from;
	bool hasNegativeCycle; //是否有负权环

public:	
   
    BellmanFord(Graph &graph,int s):G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		for(int i=0 ; i < G.V() ; i++ ){
			from.push_back(NULL);
		}
		
		//Bellman-Ford
	}
	
	~BellmanFord(){
		delete[] distTo;	
	}
	
	bool negativeCycle(){
		return hasNegativeCycle;
	}
	
	//最短路径
	Weight shortestPathTo(int w){
		assert( w>=0 && w < G.V() );
		assert( !hasNegativeCycle );
		return distTo[w];
	}
	
	bool hasPathTo(int w){
		assert( w >= 0 && w < G.V() );
		return from[w] != NULL;
	}
	
	void shortestPath(int w,vector<Edge<Weight>> &vec){
		
		assert( w>=0 && w<G.V() );
		assert( !hasNegativeCycle );
		
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
	
	void showPath(int w){
		assert( w>=0 && w<G.V() );
		assert( !hasNegativeCycle );
		
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