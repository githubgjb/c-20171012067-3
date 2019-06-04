// SortTestHelper.cpp : �������̨Ӧ�ó������ڵ㡣
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

