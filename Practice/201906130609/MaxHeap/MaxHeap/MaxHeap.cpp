// MaxHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "MaxHeap.h"
#include "MaxHeap02.h"
#include "MaxHeap03.h"
#include "sortTestHelper.h"
#include "mergeSort02.h"
#include "mergeSortBU11.h"
#include "quickSort14.h"
#include "quickSort3Ways.h"
#include "HeapSort01.h"
#include "HeapSort02.h"
#include "HeapSort03.h"
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000000;
	// 测试1 一般测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int *arr1 = sortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = sortTestHelper::copyIntArray(arr1, n);
	int *arr3 = sortTestHelper::copyIntArray(arr1, n);
	int *arr4 = sortTestHelper::copyIntArray(arr1, n);
	int *arr5 = sortTestHelper::copyIntArray(arr1, n);
	int *arr6 = sortTestHelper::copyIntArray(arr1, n);

	//todo
	sortTestHelper::testSort("Merge02 Sort",mergeSort02,arr1,n);
	sortTestHelper::testSort("quickSort14 Sort", quickSort14, arr2, n);
	sortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	sortTestHelper::testSort("heapSort01 Sort", heapSort01, arr4, n);
	sortTestHelper::testSort("heapSort02 Sort", heapSort02, arr5, n);
	sortTestHelper::testSort("heapSort03 Sort", heapSort03, arr6, n);

	delete(arr1);
	delete(arr2);
	delete(arr3);
	delete(arr4);
	delete(arr5);
	delete(arr6);

	cout << endl;

	// 测试2 测试存在包含大量相同元素的数组
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = sortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = sortTestHelper::copyIntArray(arr1, n);
	arr3 = sortTestHelper::copyIntArray(arr1, n);
	arr4 = sortTestHelper::copyIntArray(arr1, n);
	arr5 = sortTestHelper::copyIntArray(arr1, n);
	arr6 = sortTestHelper::copyIntArray(arr1, n);

	//todo
	sortTestHelper::testSort("Merge02 Sort", mergeSort02, arr1, n);
	sortTestHelper::testSort("quickSort14 Sort", quickSort14, arr2, n);
	sortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	sortTestHelper::testSort("heapSort01 Sort", heapSort01, arr4, n);
	sortTestHelper::testSort("heapSort02 Sort", heapSort02, arr5, n);
	sortTestHelper::testSort("heapSort03 Sort", heapSort03, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;


	cout << endl;


	// 测试3 测试近乎有序的数组
	int swapTimes = 100;
	//int swapTimes = 0;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = sortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = sortTestHelper::copyIntArray(arr1, n);
	arr3 = sortTestHelper::copyIntArray(arr1, n);
	arr4 = sortTestHelper::copyIntArray(arr1, n);
	arr5 = sortTestHelper::copyIntArray(arr1, n);
	arr6 = sortTestHelper::copyIntArray(arr1, n);

	//todo
	sortTestHelper::testSort("Merge02 Sort", mergeSort02, arr1, n);
	sortTestHelper::testSort("quickSort14 Sort", quickSort14, arr2, n);
	sortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	sortTestHelper::testSort("heapSort01 Sort", heapSort01, arr4, n);
	sortTestHelper::testSort("heapSort02 Sort", heapSort02, arr5, n);
	sortTestHelper::testSort("heapSort03 Sort", heapSort03, arr6, n);

	delete(arr1);
	delete(arr2);
	delete(arr3);
	delete(arr4);
	delete(arr5);
	delete(arr6);

	cout << endl;

	//MaxHeap<int> maxHeap = MaxHeap<int>(100);
	//cout << maxHeap.size() << endl;

	/*
	MaxHeap02<int> maxHeap02 = MaxHeap02<int>(100);
	cout << maxHeap02.size() << endl;

	srand(time(NULL));
	for (size_t i = 0; i < 15; i++)
	{
		maxHeap02.insert(rand() % 100);
	}
	*/

	/*
	MaxHeap03<int> maxHeap03 = MaxHeap03<int>(100);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		maxHeap03.insert(rand() % 100);
	}
	while (!maxHeap03.isEmpty())
	{
		cout << maxHeap03.extractMax() << " ";
	}
	cout << endl;
	*/

	return 0;
}

