#ifndef CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H
#define CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void insertionSort03(T arr[], int n){

	for (int i = 1; i < n; i++)
	{
		/*
		//寻找arr[i]中合适的位置
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		{
			swap(arr[j], arr[j - 1]);
		}
		*/

		T e = arr[i];
		int j;
		//寻找arr[i]中合适的位置
		for (j = i; j > 0 && arr[j-1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}

}
//对arr[l...r]范围的数组进行插入排序
template <typename T>
void insertionSort03(T arr[],int l,int r){

	for (int i = l + 1; i <= r; i++)
	{
		T e = arr[i];
		int j;
		for ( j = i; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}

		arr[j] = e;
	}

	return;
}

#endif //CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H
