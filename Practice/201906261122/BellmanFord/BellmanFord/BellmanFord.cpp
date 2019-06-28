// BellmanFord.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "BellmanFord.h"
#include "BellmanFord02.h"
#include "BellmanFord03.h"
#include "BellmanFord04.h"
#include "BellmanFord05.h"
#include "BellmanFord06.h"
#include "BellmanFord07.h"
#include "BellmanFord08.h"
#include "BellmanFord09.h"
#include "BellmanFord10.h"
#include "BellmanFord11.h"
#include "BellmanFord12.h"
#include "BellmanFord13.h"
#include "BellmanFord14.h"
#include "BellmanFord15.h"
using namespace std;

// 测试Bellman-Ford算法
int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "testG2.txt";
	//string filename = "testG_negative_circle.txt";
	int V = 5;

	SparseGraph<int> g = SparseGraph<int>(V, true);
	ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

	cout << "Test Bellman-Ford:" << endl << endl;
	BellmanFord15<SparseGraph<int>, int> bellmanFord(g, 0);
	//BellmanFord<SparseGraph<int>, int> bellmanFord(g, 0);
	if (bellmanFord.negativeCycle())
		cout << "The graph contain negative cycle!" << endl;
	else
	for (int i = 1; i < V; i++) {
		if (bellmanFord.hasPathTo(i)) {
			cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
			bellmanFord.showPath(i);
		}
		else
			cout << "No Path to " << i << endl;

		cout << "----------" << endl;
	}

	return 0;
}

