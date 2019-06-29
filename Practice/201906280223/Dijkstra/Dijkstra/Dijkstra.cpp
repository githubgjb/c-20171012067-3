// Dijkstra.cpp : 定义控制台应用程序的入口点。
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

// 测试我们的Dijkstra最短路径算法
int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "testG1.txt";
	int V = 5;

	SparseGraph<int> g = SparseGraph<int>(V, true);
	// Dijkstra最短路径算法同样适用于有向图
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

