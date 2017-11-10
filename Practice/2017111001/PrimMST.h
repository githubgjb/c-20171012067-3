
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class PrimMST{

private:	
	Graph &G;  //图相应的引用
	IndexMinHeap<Weight> ipq;
	vector<Edge<Weight>*> edgeTo; //存储横切边
	bool* marked;
	vector<Edge<Weight>> mst;
	Weight mstWeight;
	
	void visit(int v){
		//确定之前没有被访问过
		assert( !marked[v] );
		marked[v] = true;
		
		//访问顶点v所有的相临的临边
	    typename Graph::adjIterator adj(G,v);
		for(Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next()){
			//找相相临的节点
			int w = e->other(v);
			if( !marked[w] ){ //是横切边没被标记过
				//是否找到过相临的横切边
				if( !edgeTo[w] ){
					ipq.insert(w, e->wt()); // 索引为w,权值是e
				    //更新edgeTo,有和w相临的边
					edgeTo[w] = e;
				}//如果是之前找到呢
				//现在找到的比之前存的要小,就要更新了
				else if(e->wt() < edgeTo[w]->wt() ){
					edgeTo[w] = e;
					//要维护最小索引堆
					ipq.change(w,e->wt());
				}
			}
		}
	}

public:
	
	//最小索引堆开顶点个数就够了
    PrimMST(Graph &graph):G(graph),ipq(IndexMinHeap<double>(graph.V())){
		
		marked = new bool[G.V()];
		for(int i = 0 ; i<G.V() ; i++ ){
			marked[i] = false;
			edgeTo.push_bakc(NULL);
		}
		mst.clear();
		
		//Prim
		//对初始点进行访问
		visit(0);
		while( !ipq.isEmpty() ){
			int v = ipq.extractMinIndex();
			//找到相临的横切边,先要确认一下,是存在的
			assert( edgeTo[v] );
			mst.push_back( *edgeTo[v] );
			visit(v);
		}
		
		mstWeight = mst[0].wt();
		for(int i = 1; i < mst.size() ;i ++ ){
			mstWeight += mst[i].wt();
		}
	}
	
	~PrimMST(){
		delete[] marked;
	}
	
	//最小生成树的边
	vector<Edge<Weight>> mstEdges(){
		return mst;		
	};
	
	Weight result(){
		return mstWeight;
	};
	
};