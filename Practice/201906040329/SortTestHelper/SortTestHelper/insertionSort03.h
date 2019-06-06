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
		//Ѱ��arr[i]�к��ʵ�λ��
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		{
			swap(arr[j], arr[j - 1]);
		}
		*/

		T e = arr[i];
		int j;
		//Ѱ��arr[i]�к��ʵ�λ��
		for (j = i; j > 0 && arr[j-1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}

}
//��arr[l...r]��Χ��������в�������
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
