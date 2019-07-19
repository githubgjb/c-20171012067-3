// AlgoritmAndDataStructus.cpp : 定义控制台应用程序的入口点。
//

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

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000000;
	cout << "Test for Random Array,size= " << n << ",random range [0," << n << "]" << endl;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);
	int *arr3 = SortTestHelper::copyIntArray(arr, n);
	int *arr4 = SortTestHelper::copyIntArray(arr, n);
	int *arr5 = SortTestHelper::copyIntArray(arr, n);
	int *arr6 = SortTestHelper::copyIntArray(arr, n);
	int *arr7 = SortTestHelper::copyIntArray(arr, n);

	//SortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
	SortTestHelper::testSort("Merge Sort02", mergeSort02, arr3, n);
	SortTestHelper::testSort("Merge Sort03", mergeSort03, arr4, n);
	SortTestHelper::testSort("mergeSortBU Sort", mergeSortBU, arr5, n);
	SortTestHelper::testSort("quickSort Sort", quickSort, arr6, n);
	SortTestHelper::testSort("quickSort02 Sort", quickSort02, arr7, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;
	delete[] arr7;

	cout << endl;

	int swapTimes = 10;
	cout << "Test for Random Nearly Ordered Array,size= " << n << ",random range [0," << n << "],swap time = " << swapTimes << endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr, n);
	arr3 = SortTestHelper::copyIntArray(arr, n);
	arr4 = SortTestHelper::copyIntArray(arr, n);
	arr5 = SortTestHelper::copyIntArray(arr, n);
	arr6 = SortTestHelper::copyIntArray(arr, n);

	//SortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
	SortTestHelper::testSort("Merge Sort02", mergeSort02, arr3, n);
	SortTestHelper::testSort("Merge Sort03", mergeSort03, arr4, n);
	SortTestHelper::testSort("mergeSortBU Sort", mergeSortBU, arr5, n);
	SortTestHelper::testSort("quickSort02 Sort", quickSort02, arr6, n);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;

	cout << endl;

	cout << "Test for Random Array,size= " << n << ",random range [0,10]" << endl;
	arr = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr, n);
	

	SortTestHelper::testSort("Merge Sort03", mergeSort03, arr, n);
	SortTestHelper::testSort("quickSort03 Sort", quickSort03, arr2, n);

	delete[] arr;
	delete[] arr2;
	cout << "回车结束" << endl;
	getchar();
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

