
template<typename Graph,typename Weight>

class BellmanFord{

private:
	Graph &G;
	int s;
	Weight* distTo;
	vector<Edge<Weight>*> from;
	bool hasNegativeCycle; //是否有负权环
	
	//再做一轮对节点的松弛操作,如果超过v-1条边了,
	//说明产生负权环了
	bool detectNegativeCycle(){
		for(int i=0 ; i < G.V() ; i ++){
			typename Graph::adjIterator adj(G,i);
			for(Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next()){
				if(!from[e->w() || distTo[e->v()] + e->wt() <  distTo[e->w()] ]){
				   return true;
				}
			}
		}
		
		return false;
	}

public:	
   
    BellmanFord(Graph &graph,int s):G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		for(int i=0 ; i < G.V() ; i++ ){
			from.push_back(NULL);
		}
		
		//Bellman-Ford
		distTo[s] = Weight();
		
		//对每一个点进行一个v-1次的松弛操作
		for( int pass = 1 ; pass < G.V() ; pass++ ){
			
			//对所有的点的临边进行松弛操作
			for(int i = 0 ; i<G.V() ; i++){
				//对每一个点的临边进行遍历
				typename Graph::adjIterator adj(G,i);
				for(Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
					//之前没有到达过     绕道i这个点再到e
					if( !from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] ){
						//找到了,就更新了
						distTo[e->w()] = distTo[e->v()] + e->wt();
						from[e->w()] = e;
					}
				}
			}
		}
		
		//判断负权环
		hasNegativeCycle = detectNegativeCycle();
		
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