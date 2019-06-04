// SortTestHelper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sortTestHelper.h"
#include "mergeSort.h"
#include "selectionSort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	int *arr = sortTestHelper::generateRandomArray(n,0,n);

	mergeSort(arr,n);

	sortTestHelper::testSort("mergeSort",mergeSort,arr,n);

	delete(arr);
	return 0;
}

