// MargeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include "SortTestHelper.h"
using namespace std;

//将arr[l...mid]和arr[mid+1...r]两部分进行归并
//合并
template<typename T>
void __merge(T arr[], int l,int mid, int r){

	//为什么加1因为是毕区间,再换成开区间
	//T aux[r - l + 1];
	T *aux = new T[r - l + 1];
	//copy
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}

	//两个子数组开头的位置
	int i = l, j = mid + 1;
	for (int  k = l; k <= r; k++)
	{
		//数组越界的情况
		//arr[l...mid]
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		//arr[mid+1...r]
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		//一般情况
		//注意有偏移
		else if (aux[i-l] < aux[j-l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}



}

//递归使用归并排序,对arr[l....r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l,int r){

	//递归到底的情况
	if (l >= r)
	{
		return;
	}
	int mid = (l + r) / 2; //有bug
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid + 1, r);

	//将两段进行merge
	__merge(arr,l,mid,r);
}

template<typename T>
void mergeSort(T arr[], int n){

	//前毕后毕[]
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

