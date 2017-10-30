
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
				pq.insert(*e);//09:25
			}
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