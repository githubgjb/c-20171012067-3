
template<typename Graph, typename Weight>

class KruskalMST{
	
private:	
	vector<Edge<Weight>> mst; //最终求出来的mst,最小生成树
	Weight mstWeight; //权值
	
public:	
	KruskalMST(Graph &graph){
		
		//用最小堆进行排序
		MinHeap<Edge<Weight>> pq( graph.E() );
		//遍历一下图中所有的顶点
		for(int i=0 ; i < graph.V() ; i ++ ){
			//对于每一个顶点找一下所有的临边
			typename Graph::adjIterator adj(graph,i);
			for(Edge<Weight> *e = adj.begin() ; !adj.end() ; e = adj.next()){
				if( e->v() < e->w() ){
					pq.insert(*e);
				}				
			}
		}
		
		UnionFind uf(graph.V()); //开顶点个数的空间
		//构建最小生成树           //v-1条边都是了
		while( !pq.isEmpty() && mst.size() < graph.V() - 1){
			//取出最小边
			Edge<Weight> e = pq.extractMin();
			//已经连接起来不考虑
			if(uf.isConnected( e.v(),e.w() )){
				continue;
			}
			mst.push_back();//放到集合中
			uf.unionElements( e.v() , e.w() );			
		}
		
		//计算权值
		mstWeight = mst[0].wt();
		for(int i=1 ; i<mst.size() ;i++){
			mstWeight += mst[i].wt();
		}
	}
	
	~KruskalMST(){
		
	}
	
	vector<Edge<Weight>> mstEdges(){
		return mst;
	}
	
	Weight result(){
		return mstWeight;
	}

	
};