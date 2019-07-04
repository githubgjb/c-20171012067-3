// Krusk.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "KruskalMST.h"
#include "Dijkstra.h"
#include "KruskalMST02.h"
#include "KruskalMST03.h"
#include "KruskalMST04.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	// 测试我们的Dijkstra最短路径算法
	string filename = "testG2.txt";
	int V = 5;

	SparseGraph<int> g = SparseGraph<int>(V, true);
	// Dijkstra最短路径算法同样适用于有向图
	//SparseGraph<int> g = SparseGraph<int>(V, false);
	ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

	cout << "Test Dijkstra:" << endl << endl;
	Dijkstra<SparseGraph<int>, int> dij(g, 0);
	for (int i = 0; i < V; i++){
		if (dij.hasPathTo(i)){
			cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
			dij.showPath(i);
		}
		else
			cout << "No Path to " << i << endl;

		cout << "----------" << endl;
	}
	*/
	
	string filename = "testG1.txt";
	int V = 8;

	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

	// Test Kruskal MST
	cout << "Test Kruskal MST:" << endl;
	//KruskalMST<SparseGraph<double>, double> kruskalMST(g);
	KruskalMST04<SparseGraph<double>, double> kruskalMST(g);
	vector<Edge<double>> mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << kruskalMST.result() << endl;

	return 0;
}

