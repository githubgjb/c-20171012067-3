
template<typename Graph, typename Weight>
class BellmanFord{

private:
	Graph &G; //图的引用
	int s;    //原点
	Weight* distTo;             //s到i的最短路径
	vector<Edge<Weight>*> from; //最短路径中前一个节点是谁
	bool hasNegativeCycle;      //是否有负权环
	
	//检查是否有负权环
    bool detectNegativeCycle(){
		//进行松驰操作
		for(int i=0 ; i < G.V() ; i++){
			typename Graph::adjIterator adj(G,i);
			//对每一个点的临边进行遍历
			for(Edge<Weight>* e = adj.begin(); !adj.end() ; e = adj.next() ){
				  //没有到达过     //满足松驰条件
				if( !from[e->w] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
					return true;
				}
			}
		}
		return false;
	}
	
public:
 
    BellmenFord(Graph &graph,int s):G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		for(int i=0 ; i<G.V() ; i++){
			from.push_back(NULL);
		}
		
		//Bellman-Ford 
		distTo[s] = Weight();  //0
		//v-1次循环
		for(int pass = 1 ; pass < G.V() ; pass++ ){
			//进行松驰操作
			for(int i=0 ; i < G.V() ; i++){
				typename Graph::adjIterator adj(G,i);
				//对每一个点的临边进行遍历
				for(Edge<Weight>* e = adj.begin(); !adj.end() ; e = adj.next() ){
					  //没有到达过     //满足松驰条件
					if( !from[e->w] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
						distTo[e->w()] = distTo[e->v()] + e->wt();
						from[e->w()] = e;
					}
				}
			}
		}
		
		hasNegativeCycle = detectNegativeCycle();
		
		
	}

    ~BellmenFord(){
		delete[] distTo;
	}
	
	bool negativeCycle(){
		return hasNegativeCycle;
	}
	
	Weight shortestPathTo(int w){
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
