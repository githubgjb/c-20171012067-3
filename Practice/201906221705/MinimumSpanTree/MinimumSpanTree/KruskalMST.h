#ifndef INC_06_KRUSKAL_ALGORITHM_KRUSKALMST_H
#define INC_06_KRUSKAL_ALGORITHM_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UF.h"
#include "Edge.h"

using namespace std;

template <typename Graph,typename Weight>
class KruskalMST{

private:
	vector<Edge<Weight>> mst;
	Weight mstWeight;

public:
	KruskalMST(Graph &graph){
		// 将图中的所有边存放到一个最小堆中
		MinHeap<Edge<Weight>> pq(graph.E());
		for (int i = 0; i < graph.V(); i++){
			typename Graph::adjIterator adj(graph, i);
			for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next())
			if (e->v() < e->w())
				pq.insert(*e);
		}

		// 创建一个并查集, 来查看已经访问的节点的联通情况
		UnionFind uf = UnionFind(graph.V());
		while (!pq.isEmpty() && mst.size() < graph.V() - 1){

			// 从最小堆中依次从小到大取出所有的边
			Edge<Weight> e = pq.extractMin();
			// 如果该边的两个端点是联通的, 说明加入这条边将产生环, 扔掉这条边
			if (uf.isConnected(e.v(), e.w()))
				continue;

			// 否则, 将这条边添加进最小生成树, 同时标记边的两个端点联通
			mst.push_back(e);
			uf.unionElements(e.v(), e.w());
		}

		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++)
			mstWeight += mst[i].wt();
		/*
		MinHeap<Edge<Weight>> pq( graph.E() );
		for (int i = 0; i < graph.V(); i++)
		{
			typename Graph::adjIterator adj(graph,i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){				
				if (e->v() < e->w())
				{
					pq.insert(*e);
				}			
			}
		}

		UnionFind uf(graph.V());
		while (!pq.isEmpty() && mst.size() < graph.V() - 1 )
		{
			Edge<Weight> e = pq.extractMin();
			if (uf.isConnected( e.v() , e.w() ) )
			{
				continue;
			}
			mst.push_back( e );
			uf.unionElements(e.v(), e.w());
		}

		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size() ; i++)
		{
			mstWeight += mst[i].wt();
		}
		*/

	}

	~KruskalMST(){

	}
	vector<Edge<Weight>> mstEdges(){
		return mst;
	};

	Weight result(){
		return mstWeight;
	};

};




#endif //INC_06_KRUSKAL_ALGORITHM_KRUSKALMST_H