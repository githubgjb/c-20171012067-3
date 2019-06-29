// Dijkstra.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Dijkstra.h"
#include "Dijkstra02.h"
#include "Dijkstra03.h"


using namespace std;

// �������ǵ�Dijkstra���·���㷨
int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "testG1.txt";
	int V = 5;

	SparseGraph<int> g = SparseGraph<int>(V, true);
	// Dijkstra���·���㷨ͬ������������ͼ
	//SparseGraph<int> g = SparseGraph<int>(V, false);
	ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

	cout << "Test Dijkstra:" << endl << endl;
	Dijkstra03<SparseGraph<int>, int> dij(g, 0);
	for (int i = 0; i < V; i++){
		if (dij.hasPathTo(i)){
			cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
			dij.showPath(i);
		}
		else
			cout << "No Path to " << i << endl;

		cout << "----------" << endl;
	}

	return 0;
}

