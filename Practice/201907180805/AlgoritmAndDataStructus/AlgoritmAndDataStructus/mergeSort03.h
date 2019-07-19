
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void __insertionSort(T arr[], int l,int r){

	for (int i = l+1; i <= r; i++)
	{
		//寻找元素arr[i]合适的插入位置
		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}


//将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge03(T arr[], int l, int mid, int r){
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}

	}
	delete[] aux;
}

//递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort03(T arr[], int l, int r){

	/*
	if (l >= r)
	{
		return;
	}
	*/
	if (r - l <= 15)
	{
		__insertionSort(arr,l,r);
		return;

	}

	//int mid = (l + r) / 2;
	int mid = l + (r - l) / 2;
	__mergeSort03(arr, l, mid);
	__mergeSort03(arr, mid + 1, r);
	if (arr[mid] > arr[mid + 1])
	{
		__merge03(arr, l, mid, r);
	}
}

template<typename T>
void mergeSort03(T arr[], int n){
	__mergeSort03(arr, 0, n - 1);
}
