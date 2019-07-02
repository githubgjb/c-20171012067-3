// MinimumSpanTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include <ctime>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include "KruskalMST02.h"
#include "LazyPrimMST02.h"
#include "LazyPrimMST03.h"
#include "LazyPrimMST04.h"
#include "LazyPrimMST05.h"
#include "LazyPrimMST06.h"
#include "LazyPrimMST07.h"
#include "LazyPrimMST08.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "testG1.txt";
	int V = 8;

	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);


	// Test Lazy Prim MST
	cout << "Test Lazy Prim MST:" << endl;
	LazyPrimMST08<SparseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << lazyPrimMST.result() << endl;

	cout << endl;
	/*
	//kruskalMST02  类没有问题
	//MinHeap02     类没有问题
	//UF02          类没有问题
	//Edge02        类没有问题

	string filename = "testG0.txt";
	int V = 8;

	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);
	// Test Kruskal MST
	KruskalMST<SparseGraph<double>, double> kruskalMST02(g);
	vector<Edge<double>> mst = kruskalMST02.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << kruskalMST02.result() << endl;
	*/
	/*
	string filename = "testG1.txt";
	int V = 8;

	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);


	// Test Lazy Prim MST
	cout << "Test Lazy Prim MST:" << endl;
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << lazyPrimMST.result() << endl;

	cout << endl;
	
	
	// Test Kruskal MST
	cout << "Test Kruskal MST:" << endl;
	KruskalMST<SparseGraph<double>, double> kruskalMST(g);
	mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << kruskalMST.result() << endl;

	cout << endl;
	*/
	/*
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
	cout << " The MST weight is: " << lazyPrimMST.result() << endl;

	cout << endl;


	// Test Kruskal MST
	cout << "Test Kruskal MST:" << endl;
	KruskalMST<SparseGraph<double>, double> kruskalMST(g);
	mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
		cout << mst[i] << endl;
	cout << "The MST weight is: " << kruskalMST.result() << endl;
	*/
	/*
	//Test Kruskal MST
	cout << "Test Kruskal MST" << endl;
	KruskalMST<SparseGraph<double>, double> kruskalMST(g);
	mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
	{
		cout << mst[i] << endl;
	}
	cout << " The MST weight is: " << kruskalMST.result() << endl;

	cout << endl;
	*/
	/*------------------------------------------------*/
	/*
	//performance
	string filename1 = "testG1.txt";
	int V1 = 8;
	string filename2 = "testG2.txt";
	int V2 = 250;
	string filename3 = "testG3.txt";
	int V3 = 1000;
	string filename4 = "testG4.txt";
	int V4 = 10000;


	SparseGraph<double> g1 = SparseGraph<double>(V1, false);
	ReadGraph<SparseGraph<double>, double> readGraph12(g1,filename1);

	SparseGraph<double> g2 = SparseGraph<double>(V2, false);
	ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename2);

	SparseGraph<double> g3 = SparseGraph<double>(V3, false);
	ReadGraph<SparseGraph<double>, double> readGraph3(g3, filename3);

	SparseGraph<double> g4 = SparseGraph<double>(V4, false);
	ReadGraph<SparseGraph<double>, double> readGraph4(g4, filename4);

	cout << endl;

	clock_t startTime, endTime;

	cout << "Test Lazy Prim MST:" << endl;
	 
	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST1(g1);
	endTime = clock();
	cout << "Test for G1: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;


	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST2(g2);
	endTime = clock();
	cout << "Test for G2: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;


	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST3(g3);
	endTime = clock();
	cout << "Test for G3: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;


	startTime = clock();
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST4(g4);
	endTime = clock();
	cout << "Test for G4: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	//Test Prim MST

	cout << "Test Prim MST:" << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST1(g1);
	endTime = clock();
	cout << "Test for G1: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST2(g2);
	endTime = clock();
	cout << "Test for G2: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST3(g3);
	endTime = clock();
	cout << "Test for G3: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;

	startTime = clock();
	PrimMST<SparseGraph<double>, double> PrimMST4(g4);
	endTime = clock();
	cout << "Test for G4: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
	*/


	/*---------------------------------------------------------------------------------------------*/

	/*
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
	

	//Test Prim MST
	cout << "Test Prim MST" << endl;
	PrimMST<SparseGraph<double>, double> primMST(g);
	mst = primMST.mstEdges();
	for (int i = 0; i < mst.size(); i++){
		cout << mst[i] << endl;
	}
	cout << " The MST weight is: " << primMST.result() << endl;
	cout << endl;
	*/

	/*
	string filename = "testG1.txt";
	int V = 8;
	//输出的精确度是两位小数
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

