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
		// ��ͼ�е����бߴ�ŵ�һ����С����
		MinHeap<Edge<Weight>> pq(graph.E());
		for (int i = 0; i < graph.V(); i++){
			typename Graph::adjIterator adj(graph, i);
			for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next())
			if (e->v() < e->w())
				pq.insert(*e);
		}

		// ����һ�����鼯, ���鿴�Ѿ����ʵĽڵ����ͨ���
		UnionFind uf = UnionFind(graph.V());
		while (!pq.isEmpty() && mst.size() < graph.V() - 1){

			// ����С�������δ�С����ȡ�����еı�
			Edge<Weight> e = pq.extractMin();
			// ����ñߵ������˵�����ͨ��, ˵�����������߽�������, �ӵ�������
			if (uf.isConnected(e.v(), e.w()))
				continue;

			// ����, ����������ӽ���С������, ͬʱ��Ǳߵ������˵���ͨ
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