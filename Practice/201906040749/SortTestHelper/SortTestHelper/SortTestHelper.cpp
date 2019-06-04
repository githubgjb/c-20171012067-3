// SortTestHelper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sortTestHelper.h"
#include "selectionSort.h"
#include "mergeSort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000000;
	int *arr = sortTestHelper::generateRandomArray(n,0,n);

	//selectionSort(arr,n);
	//sortTestHelper::printArray(arr,n);

	//mergeSort(arr,n);
	//sortTestHelper::printArray(arr,n);

	//sortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	sortTestHelper::testSort("mergeSort Sort", mergeSort, arr, n);

	delete(arr);

	return 0;
}

