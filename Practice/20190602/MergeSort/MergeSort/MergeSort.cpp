// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include "SortTestHelper.h"
using namespace std;

//arr[l...mid]  arr[mid+1...r]
template<typename T>
void __merge(T arr[],int l,int mid,int r){

	T *aux = new T[r-l+1];
	for (int i = l; i <= r; i++)
	{
		aux[i-l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i>mid){
			arr[k] = aux[j - l];
			j++;
		}
		else if (j>r){
			arr[k] = aux[i - l];
			i++;
		}else if (aux[i-l] < aux[j-l]){
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}

}

template<typename T>
void __mergeSort(T arr,int l,int r){

	if (l>=r)
	{
		return;
	}
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	__merge(arr,l,mid,r);

}

template<typename T>
void mergeSort(T arr[],int n){

	__mergeSort(arr,0,n-1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 500000;
	// 测试1 一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);

	delete[] arr1;

	cout << endl;
	return 0;
}

