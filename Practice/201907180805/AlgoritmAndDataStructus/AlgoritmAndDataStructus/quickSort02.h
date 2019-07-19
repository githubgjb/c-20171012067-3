#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void __insertionSortQuickSort02(T arr[], int l, int r){

	for (int i = l + 1; i <= r; i++)
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


//对arr[l...r]部分进行partition操作
//p arr[l...p-1] < arr[p]   arr[p+1...r] > arr[p]
template<typename T>
int __partition02(T arr[], int l, int r){

	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];
	//arr[l+1...j] < v ; arr[j+1..i] > v
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

template<typename T>
void __quickSort02(T arr[], int l, int r){
	/*
	if (l >= r)
	{
		return;
	}
	*/
	if ( r-l <= 15)
	{
		__insertionSortQuickSort02(arr, l, r);
		return;
	}

	int p = __partition02(arr, l, r);
	__quickSort02(arr, l, p - 1);
	__quickSort02(arr, p + 1, r);
}

template<typename T>
void quickSort02(T arr[], int n){
	srand(time(NULL));
	__quickSort02(arr, 0, n - 1);
}