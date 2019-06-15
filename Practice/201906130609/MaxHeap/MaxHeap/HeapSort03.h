#ifndef CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_heapSort03
#define CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_heapSort03

#include <algorithm>

using namespace std;

template <typename T>
void __shiftDown(T arr[],int n,int k){
	while (2 * k + 1 < n)
	{
		int j = 2 * k + 1; //在此轮循环中,arr[k]和arr[j]交换位置
		if (j + 1 < n && arr[j + 1] > arr[j])
		{
			j += 1;
		}
		if (arr[k] >= arr[j])
		{
			break;
		}
		swap(arr[k], arr[j]);
		k = j;

	}
}

template <typename T>
void heapSort03(T arr[], int n){

	//heapify
	for (int i = (n-1)/2; i >= 0; i--)
	{
		__shiftDown(arr, n, i);
	}

	for (int i = n-1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}

}

#endif //CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H