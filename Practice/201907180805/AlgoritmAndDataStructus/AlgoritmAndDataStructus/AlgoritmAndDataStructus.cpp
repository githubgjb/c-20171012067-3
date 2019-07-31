// AlgoritmAndDataStructus.cpp : 定义控制台应用程序的入口点。
//


#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>
#include <ctime>
#include "stdafx.h"
#include "SelectionSort.h"
#include "SelectionSort02.h"
#include <stdio.h>
#include <string>
#include "SortTestHelper.h"
#include "insertionSort.h"
#include "insertionSort02.h"
#include "mergeSort.h"
#include "mergeSort02.h"
#include "mergeSort03.h"
#include "mergeSortBU.h"
#include "quickSort.h"
#include "quickSort02.h"
#include "quickSort03.h"
#include "quickSort3Ways.h"
#include "MaxHeap.h"
#include "heapSort01.h"
#include "heapSort02.h"
#include "heapSort03.h"
#include "BST.h"
#include "FileOps.h"
#include "UnionFindTestHelper.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
#include "DenseGraphEdge.h"
#include "ReadGraphEdge.h"
#include "SparseGraphEdge.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"
//#include "Dijkstra.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	string filename = "testG2Dijkstra.txt";
	int V = 5;
	SparseGraphEdge<int> g = SparseGraphEdge<int>(V, false);
	ReadGraphEdge<SparseGraphEdge<int>, int> readGraph(g, filename);

	cout << "Test Dijkstra:" << endl;
	GraphDijkistra::Dijkstra<SparseGraphEdge<int>, int> dij(g, 0);
	for (int i = 1; i < V; i++)
	{
		cout << "Shortest Path to" << i<< ":" <<dij.shortestPathTo(i) << endl;
		dij.showPath(i);
		cout << "-------------------" << endl;
	}

	cout << "回车结束" << endl;
	getchar();
	*/
	/*--------------------------------*/
	
	string filename = "testEdgeG0.txt";
	int V = 8;

	SparseGraphEdge<double> g = SparseGraphEdge<double>(V, false);
	ReadGraphEdge<SparseGraphEdge<double>, double> readGraph2(g, filename);
	//Test Lazy Prim MST

	cout << "Test Lazy Prim MST:" << endl;

	lazyPrimMST<SparseGraphEdge<double>, double> lazyPrimMST(g);

	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
	{
		cout << mst[i] << endl;
	}
	cout << "The MST Weight is:" << lazyPrimMST.result() << endl;
	cout << endl;

	//Test Prim MST
	cout << "Test Prim MST:" << endl;
	PrimMST<SparseGraphEdge<double>,double> primMST(g);
	mst = primMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
	{
		cout << mst[i] << endl;
	}
	cout << "The MST Weight is:" << primMST.result() << endl;
	cout << endl;

	//Test KruskaMST MST
	cout << "Test KruskaMST MST:" << endl;
	KruskalMST<SparseGraphEdge<double>,double> kruskalMST(g);
	mst = kruskalMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
	{
		cout << mst[i] << endl;
	}
	cout << "The MST Weight is:" << primMST.result() << endl;
	cout << endl;


	cout << "回车结束" << endl;
	getchar();
	
	/*------------------------------*/
	/*
	string filename = "testEdgeG0.txt";
	int V = 8;
	//输出的精确度是两位小数
	//cout << fixed << setprecision(2);
	//Test Weighted Dense Graph
	
	DenseGraphEdge<double> g1 = DenseGraphEdge<double>(V, false);
	ReadGraphEdge<DenseGraphEdge<double>, double> readGraph1(g1, filename);
	g1.show();
	cout << endl;
	

	//Test Weighted Sparse Graph
	SparseGraphEdge<double> g2 = SparseGraphEdge<double>(V, false);
	ReadGraphEdge<SparseGraphEdge<double>, double> readGraph2(g2, filename);
	g2.show();
	cout << endl;

	cout << "回车结束" << endl;
	getchar();
	*/
	/*------------------------------*/
	/*
	string filename = "testG2.txt";
	SparseGraph g(7, false);
	ReadGraph<SparseGraph> readGraph2(g, filename);
	g.show();
	cout << endl;
	
	Path<SparseGraph> dfs(g,0);
	cout << "DFS : ";
	dfs.showPath(6);
	
	ShortestPath<SparseGraph> bfs(g,0);
	cout << "BFS : ";
	bfs.showPath(6);

	cout << "回车结束" << endl;
	getchar();
	*/
	/*------------------------------*/
	/*
	string filename = "testG1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1,filename);
	//g1.show();
	Component<SparseGraph> component1(g1);
	cout << "testG1.txt,Component Count" << component1.count() << endl;

	cout << endl;

	string filename2 = "testG2.txt";
	DenseGraph g2(7, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename2);
	//g2.show();
	Component<DenseGraph> component2(g2);
	cout << "testG2.txt,Component Count" << component2.count() << endl;

	cout << "回车结束" << endl;
	getchar();
	*/
	/*------------------------------*/
	/*
	//int n = 10000;
	int n = 1000000;
	//UnionFindTestHelper::testUF1(n);
	//UnionFindTestHelper::testUF2(n);
	UnionFindTestHelper::testUF3(n);
	UnionFindTestHelper::testUF4(n);
	UnionFindTestHelper::testUF5(n);

	cout << "回车结束" << endl;
	getchar();
	*/
	/*--------------------------------------*/

	/*
	// 我们使用文本量更小的共产主义宣言进行试验:)
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words)) {
	
		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// 测试1, 我们按照文本原有顺序插入进二分搜索树
		time_t startTime = clock();
		BST<string, int> *bst = new BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst).search(*iter);
			if (res == NULL)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// 我们查看unite一词的词频
		if (bst->contain("unite"))
			cout << "'unite' : " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;
	}


	cout << "回车结束" << endl;
	getchar();
	*/
	/*------------------------*/
	/*
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	//cout << maxHeap.size() << endl;

	srand(time(NULL));
	for (int i = 0; i < 31; i++)
	{
		maxHeap.insert(rand()%100);
	}
	while (!maxHeap.isEmpty())
	{
		cout << maxHeap.extractMax() << " ";
	}
	cout << endl;

	cout << "回车结束" << endl;
	getchar();
	*/
	/*------------------------------------*/
	/*
	int n = 1000000;
	cout << "Test for Random Array,size= " << n << ",random range [0," << n << "]" << endl;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	int *arr4 = SortTestHelper::copyIntArray(arr, n);
	int *arr5 = SortTestHelper::copyIntArray(arr, n);
	int *arr6 = SortTestHelper::copyIntArray(arr, n);
	int *arr7 = SortTestHelper::copyIntArray(arr, n);
	int *arr8 = SortTestHelper::copyIntArray(arr, n);
	int *arr9 = SortTestHelper::copyIntArray(arr, n);
	int *arr10 = SortTestHelper::copyIntArray(arr, n);


	//SortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
	SortTestHelper::testSort("Merge Sort02", mergeSort02, arr3, n);
	SortTestHelper::testSort("Merge Sort03", mergeSort03, arr4, n);
	SortTestHelper::testSort("mergeSortBU Sort", mergeSortBU, arr5, n);
	SortTestHelper::testSort("quickSort Sort", quickSort, arr6, n);
	SortTestHelper::testSort("quickSort02 Sort", quickSort02, arr7, n);
	SortTestHelper::testSort("heapSort01 Sort", heapSort01, arr8, n);
	SortTestHelper::testSort("heapSort02 Sort", heapSort02, arr9, n);
	SortTestHelper::testSort("heapSort03 Sort", heapSort03, arr10, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;

	cout << endl;

	int swapTimes = 10;
	cout << "Test for Random Nearly Ordered Array,size= " << n << ",random range [0," << n << "],swap time = " << swapTimes << endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr, n);
	arr3 = SortTestHelper::copyIntArray(arr, n);
	arr4 = SortTestHelper::copyIntArray(arr, n);
	arr5 = SortTestHelper::copyIntArray(arr, n);
	arr6 = SortTestHelper::copyIntArray(arr, n);
	arr8 = SortTestHelper::copyIntArray(arr, n);
	arr9 = SortTestHelper::copyIntArray(arr, n);
	arr10 = SortTestHelper::copyIntArray(arr, n);

	//SortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
	SortTestHelper::testSort("Merge Sort02", mergeSort02, arr3, n);
	SortTestHelper::testSort("Merge Sort03", mergeSort03, arr4, n);
	SortTestHelper::testSort("mergeSortBU Sort", mergeSortBU, arr5, n);
	SortTestHelper::testSort("quickSort02 Sort", quickSort02, arr6, n);
	SortTestHelper::testSort("heapSort01 Sort", heapSort01, arr8, n);
	SortTestHelper::testSort("heapSort02 Sort", heapSort02, arr9, n);
	SortTestHelper::testSort("heapSort03 Sort", heapSort03, arr10, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;

	cout << endl;

	cout << "Test for Random Array,size= " << n << ",random range [0,10]" << endl;
	arr = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr, n);
	arr3 = SortTestHelper::copyIntArray(arr, n);
	arr8 = SortTestHelper::copyIntArray(arr, n);
	arr9 = SortTestHelper::copyIntArray(arr, n);
	arr10 = SortTestHelper::copyIntArray(arr, n);


	SortTestHelper::testSort("Merge Sort03", mergeSort03, arr, n);
	SortTestHelper::testSort("quickSort03 Sort", quickSort03, arr2, n);
	SortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	SortTestHelper::testSort("heapSort01 Sort", heapSort01, arr8, n);
	SortTestHelper::testSort("heapSort02 Sort", heapSort02, arr9, n);
	SortTestHelper::testSort("heapSort03 Sort", heapSort03, arr10, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr8;
	delete[] arr9;
	delete[] arr10;

	cout << "回车结束" << endl;
	getchar();
	*/
	/*--------------------------------------------------*/
	/*
	int n = 10000;
	//int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);

	SortTestHelper::testSort("Selection Sort",selectionSort02,arr,n);
	SortTestHelper::testSort("Insertion Sort",insertionSort,arr2,n);
	SortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr3, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;


	cout << "回车结束" << endl;
	getchar();
	*/

	/*----------------------------*/
	/*
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n,0,n);
	selectionSort02(arr,n);
	SortTestHelper::parintArray(arr,n);
	delete[] arr;
	*/	

	/*-------------------------------*/
	/*
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	//selectionSort(a,10);
	selectionSort02(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	*/
	
	return 0;
}

