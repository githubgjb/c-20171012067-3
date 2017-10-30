
template<typename Graph,typename Weight>
class PrimMST{
private:
	Graph &G;
	IndexMinHeap<Weight> ipq;
	vector<Edge<Weight>*> edgeTo;//存最短的横切边
	bool* marked;  //存点
	vector<Edge<Weight>> mst; //最小生成树所有的边
	Weight mstWeight; //存权值
	
	void visit(int v){
		
		assert(!marked[v]);//没有被访问过
		marked[v] = true;
		
		//访问顶点v相临的临边
		typename Graph::adjIterator adj(G,v);
		for(Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next()){
			
			int w = e->other(v); //根据一点,得出另一点
			if( !marked[w] ){//没有被标记过,才是横切边
				if( !edgeTo[w] ){ //没有找过最短的横切边
					ipq.insert(w,e->wt());//那个点,对应的权值
					edgeTo[w] = e;//更新了
				}
				//找到更小的权值的边了
				else if(e->wt() < edgeTo[w]->wt() ){
					edgeTo[w] = e; //更新
					ipq.change(w , e->wt());//更新最小索引堆
				}
			}
			
		}
	}
	
public:
    PrimMST(Graph &graph):G(Graph),ipq(IndexMinHeap<double>(graph.V())){
		marked = new bool[G.V()];
		for(int i=0 ; i<G.V(); i++){
			marked[i] = false;
			edgeTo.push_back(NULL)			
		}
		mst.clear();
		
		//Prim
		visit(0); //初始点做处理
		while( !ipq.isEmpty() ){
			int v = ipq.extractMinIndex();
			assert( edgeTo[v] ); //确认那个横切边是存在的
			mst.push_back( *edgeTo[v] );//放到最小生成树中
			visit(v);//放入新的顶点
		}
		
		//再算最小权值
		mstWeight = mst[0].wt();
		for(int i=1 ; i<mst.size() ; i++){
			mstWeight += mst[i].wt();
		}
		
	}
	~PrimMST(){
		delete[] marked;
	}
	
	//返回最小生成树的边
	vector<Edge<Weight>> mstEdges(){
		return mst;
	}
	
	//返回权值
	Weight result(){
		return mstWeight;
	}
}