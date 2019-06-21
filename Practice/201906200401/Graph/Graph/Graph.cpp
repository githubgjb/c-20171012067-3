// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"

int _tmain(int argc, _TCHAR* argv[])
{
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

