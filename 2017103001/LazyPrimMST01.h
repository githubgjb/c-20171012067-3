
#include "MinHeap01.h"

template<typename Graph, typename Weight>
class LazyPrimMST{

private:
	Graph &G;
	MinHeap<Edge<Weight>> pq;	
	//这个点是不是被标记了
	bool *marked;//节点一个个从蓝色到红色
	
	//最小生成树就是v-1个边
	vector<Edge<Weight>> mst;
	
	//最小生成树的权值
	Weight mstWeight;
	
	void visit(int v){
		
		//是蓝色的,还没变红色
		assert( !marked[v] );
		marked[v] = true;
		
		//新转的的红色节点的所有临边
		typename Graph::adjIterator adj(G,v);
		for(Edge<Weight>* e = adj.begin() ; !adj.end(); e = adj.next() ){
			if(!marked[e->other(v)]){
				pq.insert(*e);
			}
		}
		
		
	}
	
public:
	LazyPrimMST(Graph &graph):G(graph),pq(MinHeap<Edge<Weight>>(graph.E())){
		
		            //顶点的个数
		marked = new bool[G.V()];
		for(int i=0 ;i<G.V() ;i++){
			marked[i] = false;
		}
		mst.clear();
		
		//Lazy Prim
		visit(0);//把0结点相临的边都放入最小堆中了
		while(!pq.isEmpty()){
			//取出优先队列中最小的边
			Edge<Weight> e = pq.extractMin();
			//不是横切边,形成环了
			if(marked[e.v() == market[e.w()]]){
				continue;
			}
			mst.push_back( e );
			if( !marked[e.v()] ){//找到蓝色端点
				visit(e.v());
			}else{
				visit(e.w());
			}		
		}
		
		//计算权值
		mstWeight = mst[0].wt();
		for(int i=1 ;i<mst.size() ; i++){
			mstWeight += mst[i].wt();
		}
		
	}
	
	~LazyPrimMST(){
		delete[] marked;		
	}
	
	vector<Edge<Weight> mstEdges>{
		return mst;
	};
	
	Weight result(){
		return mstWeight;
	};
};