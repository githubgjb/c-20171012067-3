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


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	string filename = "testG1.txt";
	int V = 8;

	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

	// Test Kruskal MST
	cout << "Test Kruskal MST:" << endl;
	KruskalMST<SparseGraph<double>, double> kruskalMST(g);
	vector<Edge<double>> mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << kruskalMST.result() << endl;
	*/
	return 0;
}

