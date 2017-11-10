
#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UnionFind.h"
#include "Edge.h"

using namespace std;

template <typename Graph, typename Weight>
class KruskalMST{

private:
    //最小生成树
	vector<Edge<Weight>> mst;
	//最小生成树的权值
	Weight mstWeight;

public:
	
	KruskalMST(Graph &graph){
				
		//对所有的边进行排序
		//使用堆排序
		MinHeap<Edge<Weight>> pq( graph.E() );
		//遍历一下图中的每个点
		for(int i = 0 ; i < graph.V() ;i++){
			
			//找一下每一个顶点所有的临边
			typename Graph:adjIterator adj(graph,i);
			//临边迭代器
			for(Edge<Weight> *e = adj.begin() ; !adj.end() ; e = adj.next() ){
				//无向图存两遍,这里只放一遍
				if( e->v() < e->w() ){
					//把边放入最小堆中
					pq.insert( *e );
				}				
			}			
		}
		
		//判断是否有环,开的个数是顶点个数
		UnionFind uf(graph.V());
		
		//最小生成树 ,最小生成树的边数<=V - 1也可以停止了 
		while( !pq.isEmpty() && mst.size() < graph.V() - 1){
			Edge<Weight> e = pq.extractMin();
			
			//判断是否连接在一起了(形成环了)
			if( uf.isConnected(e.v() , e.w()) ){
				continue;
			}
			mst.push_back( e );
			uf.unionElements( e.v() ,e.w() );
		}
		
		//计算一下权值
		mstWeight = mst[0].wt();
		for(i = 1; i<mst.size() ; i++){
			mstWeight + mst[i].wt();			
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