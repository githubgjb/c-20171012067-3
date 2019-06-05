// SortTestHelper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sortTestHelper.h"
#include "mergeSort.h"
#include "selectionSort.h"
#include "insertionSort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	int *arr = sortTestHelper::generateRandomArray(n,0,n);
	int *arr2 = sortTestHelper::copyIntArray(arr,n);

	//mergeSort(arr,n);

	//sortTestHelper::testSort("mergeSort",mergeSort,arr,n);

	sortTestHelper::testSort("Insertion Sort",insertionSort,arr,n);
	sortTestHelper::testSort("Selection Sort",selectionSort,arr2,n);

	delete(arr);
	delete(arr2);
	return 0;
}

