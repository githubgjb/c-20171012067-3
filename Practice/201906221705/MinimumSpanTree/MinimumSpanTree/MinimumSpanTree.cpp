// MinimumSpanTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "testG1.txt";
	int V = 8;
	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g, filename);
	
	//Test Lazy Prim MST
	cout << "Test Lazy Prim MST" << endl;
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
	{
		cout << mst[i] << endl;
	}
	cout << " The MST weight is: "<< lazyPrimMST.result() << endl;

	cout << endl;
	/*
	string filename = "testG1.txt";
	int V = 8;
	//����ľ�ȷ������λС��
	cout << fixed << setprecision(2);
	//Test Weighted Dense Graph
	DenseGraph<double> g1 = DenseGraph<double>(V,false);
	ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
	g1.show();
	cout << endl;

	//Test Weighted Sparse Graph
	SparseGraph<double> g2 = SparseGraph<double>(V,false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
	g2.show();
	cout << endl;
	*/
	return 0;
}
