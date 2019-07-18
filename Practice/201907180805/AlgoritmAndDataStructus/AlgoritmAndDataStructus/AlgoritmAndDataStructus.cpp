// AlgoritmAndDataStructus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SelectionSort.h"
#include "SelectionSort02.h"
#include <stdio.h>
#include <string>
#include "SortTestHelper.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	
	SortTestHelper::testSort("Selection Sort",selectionSort02,arr,n);

	delete[] arr;


	cout << "�س�����" << endl;
	getchar();
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

