// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "ShortestPath.h"
#include "Path.h"
#include "SparseGraph06.h"
#include "DenseGraph06.h"
#include "SparseGraph07.h"
#include "DenseGraph07.h"
#include "SparseGraph08.h"
#include "DenseGraph08.h"
#include "SparseGraph09.h"
#include "DenseGraph09.h"
#include "SparseGraph10.h"
#include "DenseGraph10.h"
#include "SparseGraph11.h"
#include "DenseGraph11.h"
#include "SparseGraph12.h"
#include "DenseGraph12.h"

int _tmain(int argc, _TCHAR* argv[])
{

	string filename = "testG1.txt";

	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename);
	g1.show();

	cout << endl;
	cout << endl;

	DenseGraph g2(13, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename);
	g2.show();

	/*
	int N = 20;
	int M = 100;
	srand(time(NULL));
	//Sparse Graph
	SparseGraph12 g1(N, false);
	for (int i = 0; i < M; i++)
	{
	int a = rand() % N;
	int b = rand() % N;
	g1.addEdge( a , b );
	}
	//o(E)
	for (int v = 0; v < N; v++)
	{
	cout << v << " : ";
	SparseGraph12::adjIterator adj(g1, v);
	for (int w = adj.begin() ; !adj.end(); w=adj.next())
	{
	cout << w << " ";
	}
	cout << endl;
	}

	cout << endl;

	//Dense Graph
	DenseGraph12 g2(N, false);
	for (int i = 0; i < M; i++)
	{
		int a = rand() % N;
		int b = rand() % N;
		g2.addEdge(a, b);
	}
	//o(V^2)
	for (int v = 0; v < N; v++)
	{
		cout << v << " : ";
		DenseGraph12::adjIterator adj(g2, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
		{
			cout << w << " ";
		}
		cout << endl;
	}

	cout << endl;
	*/
	/*---------------------------------------*/

	/*
	string filename = "testG2.txt";
	SparseGraph g = SparseGraph(7, false);
	ReadGraph<SparseGraph> readGraph2(g, filename);
	g.show();
	cout << endl;

	Path<SparseGraph> dfs(g,0);
	cout << "DFS : ";
	dfs.showPath(6);

	
	ShortestPath<SparseGraph> bfs(g,0);
	cout << "BFS : ";
	bfs.showPath(6);
	*/
	
	/*
	//TestG1.txt
	string filename1 = "testG1.txt";
	SparseGraph g1 = SparseGraph(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename1);
	Component<SparseGraph> component1(g1);
	cout << "TestG1.txt , Component Count:" << component1.count() << endl;

	//TestG2.txt
	string filename2 = "testG2.txt";
	SparseGraph g2 = SparseGraph(7, false);
	ReadGraph<SparseGraph> readGraph2(g2, filename2);
	Component<SparseGraph> component2(g2);
	cout << "TestG2.txt , Component Count:" << component2.count() << endl;
	*/
	
	/*
	string filename = "testG1.txt";

	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename);
	g1.show();

	cout << endl;
	cout << endl;

	DenseGraph g2(13, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename);
	g2.show();
	*/
	/*
	int N = 20;
	int M = 100;
	srand(time(NULL));
	//Sparse Graph
	SparseGraph g1(N, false);
	for (int i = 0; i < M; i++)
	{
		int a = rand() % N;
		int b = rand() % N;
		g1.addEdge( a , b );
	}
	//o(E)
	for (int v = 0; v < N; v++)
	{
		cout << v << " : ";
		SparseGraph::adjIterator adj(g1, v);
		for (int w = adj.begin() ; !adj.end(); w=adj.next())
		{
			cout << w << " ";
		}
		cout << endl;
	}

	cout << endl;

	//Dense Graph
	DenseGraph g2(N, false);
	for (int i = 0; i < M; i++)
	{
		int a = rand() % N;
		int b = rand() % N;
		g2.addEdge(a, b);
	}
	//o(V^2)
	for (int v = 0; v < N; v++)
	{
		cout << v << " : ";
		DenseGraph::adjIterator adj(g2, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
		{
			cout << w << " ";
		}
		cout << endl;
	}

	cout << endl;
	*/

	/*
	vector<int> arr{1,2,3,4,5};
	vector<int>::iterator iter;
	for (iter = arr.begin(); iter != arr.end(); iter ++)
	{
		cout << *iter << endl;
	}
	cout << endl;
	*/
	/*
	// 注：如果参数为const vector<int> 需要用const_iterator
	vector<int> v{ 1, 2, 3, 4, 5 };
	vector<int>::iterator it = v.begin();
	// vector<int>::const_iterator iter=v.begin();
	for (; it != v.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
	*/
	return 0;
}

