// MinimumSpanTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
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

	return 0;
}

