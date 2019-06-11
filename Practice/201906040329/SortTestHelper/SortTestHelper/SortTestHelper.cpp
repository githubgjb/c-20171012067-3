// SortTestHelper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sortTestHelper.h"
#include "mergeSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "insertionSort02.h"
#include "insertionSort03.h"
#include "insertionSort04.h"
#include "insertionSort05.h"
#include "insertionSort06.h"
#include "insertionSort07.h"
#include "mergeSort02.h"
#include "mergeSortBU.h"
#include "mergeSortBU02.h"
#include "mergeSortBU03.h"
#include "mergeSortBU04.h"
#include "mergeSortBU05.h"
#include "mergeSortBU06.h"
#include "mergeSortBU07.h"
#include "mergeSortBU09.h"
#include "mergeSortBU10.h"
#include "mergeSortBU11.h"
#include "quickSort01.h"
#include "quickSort02.h"
#include "quickSor03.h"
#include "quickSort04.h"
#include "quickSort05.h"
#include "quickSort06.h"
#include "quickSort07.h"
#include "quickSort08.h"
#include "quickSort09.h"
#include "quickSort10.h"
int _tmain(int argc, _TCHAR* argv[])
{

	int n = 1000000;
	// 测试1 一般测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int *arr1 = sortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = sortTestHelper::copyIntArray(arr1, n);
	int *arr3 = sortTestHelper::copyIntArray(arr1, n);
	int *arr4 = sortTestHelper::copyIntArray(arr1, n);

	//sortTestHelper::testSort("Insertion07 Sort", insertionSort07, arr1, n);
    sortTestHelper::testSort("MergeSort02 Sort", mergeSort02, arr3, n);
	//sortTestHelper::testSort("mergeSortBU Sort", mergeSortBU, arr3, n);
	sortTestHelper::testSort("mergeSortBU11 Sort", mergeSortBU11, arr1, n);
	sortTestHelper::testSort("quickSort01 Sort", quickSort01, arr2, n);
	sortTestHelper::testSort("quickSort10 Sort", quickSort10, arr4, n);

	delete(arr1);
	delete(arr2);
	delete(arr3);
	delete(arr4);

	cout << endl;

	/*
	// 测试3 测试近乎有序的数组
	//int swapTimes = 10;
	int swapTimes = 0;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = sortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = sortTestHelper::copyIntArray(arr1, n);
	arr3 = sortTestHelper::copyIntArray(arr1, n);

	sortTestHelper::testSort("Insertion07 Sort", insertionSort07, arr1, n);
	sortTestHelper::testSort("MergeSort02 Sort", mergeSort02, arr2, n);
	sortTestHelper::testSort("mergeSortBU Sort", mergeSortBU, arr3, n);

	delete(arr1);
	delete(arr2);
	delete(arr3);

	cout << endl;
	*/

	/*
	int n = 50000;
	//int *arr = sortTestHelper::generateRandomArray(n, 0, 3);
	int *arr = sortTestHelper::generateRandomArray(n,0,n);
	//int *arr = sortTestHelper::generateNearlyOrderedArray(n,10);
	int *arr2 = sortTestHelper::copyIntArray(arr,n);
	int *arr3 = sortTestHelper::copyIntArray(arr, n);
	int *arr4 = sortTestHelper::copyIntArray(arr, n);

	//mergeSort(arr,n);

	//sortTestHelper::testSort("mergeSort",mergeSort,arr,n);

	//sortTestHelper::testSort("Insertion Sort",insertionSort,arr,n);
	//sortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr3, n);
	//sortTestHelper::testSort("Insertion03 Sort", insertionSort03, arr4, n);
	//sortTestHelper::testSort("Selection Sort",selectionSort,arr2,n);
	//sortTestHelper::testSort("Insertion04 Sort", insertionSort04, arr4, n);
	//sortTestHelper::testSort("Insertion05 Sort", insertionSort05, arr4, n);
	//sortTestHelper::testSort("Insertion06 Sort", insertionSort06, arr4, n);
	sortTestHelper::testSort("Insertion07 Sort", insertionSort07, arr4, n);
	sortTestHelper::testSort("MergeSort02 Sort", mergeSort02, arr3, n);
	delete(arr);
	delete(arr2);
	delete(arr3);
	delete(arr4);
	*/


	return 0;
}

