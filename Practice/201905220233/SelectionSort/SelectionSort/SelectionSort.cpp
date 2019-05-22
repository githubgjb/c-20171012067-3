// SelectionSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[],int n){
	for (int i = 0; i < n; i++)
	{
		//Ѱ��[i,n)����Сֵ
		int minIndex = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j]<arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);


	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(arr,10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
 
	return 0;
}

