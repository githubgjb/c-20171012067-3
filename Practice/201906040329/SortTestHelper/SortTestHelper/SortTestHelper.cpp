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


int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	//int *arr = sortTestHelper::generateRandomArray(n, 0, 3);
	//int *arr = sortTestHelper::generateRandomArray(n,0,n);
	int *arr = sortTestHelper::generateNearlyOrderedArray(n,10);
	int *arr2 = sortTestHelper::copyIntArray(arr,n);
	int *arr3 = sortTestHelper::copyIntArray(arr, n);
	int *arr4 = sortTestHelper::copyIntArray(arr, n);

	//mergeSort(arr,n);

	//sortTestHelper::testSort("mergeSort",mergeSort,arr,n);

	//sortTestHelper::testSort("Insertion Sort",insertionSort,arr,n);
	//sortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr3, n);
	//sortTestHelper::testSort("Insertion03 Sort", insertionSort03, arr4, n);
	//sortTestHelper::testSort("Selection Sort",selectionSort,arr2,n);
	sortTestHelper::testSort("Insertion04 Sort", insertionSort04, arr4, n);

	delete(arr);
	delete(arr2);
	delete(arr3);
	delete(arr4);
	return 0;
}

