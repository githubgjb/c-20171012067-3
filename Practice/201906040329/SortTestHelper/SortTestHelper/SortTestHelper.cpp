// SortTestHelper.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "sortTestHelper.h"
#include "mergeSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "insertionSort02.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	int *arr = sortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = sortTestHelper::copyIntArray(arr,n);
	int *arr3 = sortTestHelper::copyIntArray(arr, n);

	//mergeSort(arr,n);

	//sortTestHelper::testSort("mergeSort",mergeSort,arr,n);

	sortTestHelper::testSort("Insertion Sort",insertionSort,arr,n);
	sortTestHelper::testSort("Insertion02 Sort", insertionSort02, arr3, n);
	sortTestHelper::testSort("Selection Sort",selectionSort,arr2,n);
	

	delete(arr);
	delete(arr2);
	delete(arr3);
	return 0;
}

