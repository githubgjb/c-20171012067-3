// SortTestHelper.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[],int n){

	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j]<arr[minIndex])
			{
				minIndex = j;
			}

		}
		swap(arr[i],arr[minIndex]);
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	//int arr[] = {10,9,8,7,6,5,4,3,2,1};
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n,0,n);

	//selectionSort(arr,10);
	selectionSort(arr, n);

	/*
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;
	*/
	SortTestHelper::printArray(arr,n);
	

	delete[] arr;

	return 0;
}

