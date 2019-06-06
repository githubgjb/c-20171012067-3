#ifndef CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_HinsertionSort03
#define CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_HinsertionSort03


#include "insertionSort03.h"

using namespace std;

//将arr[l...mid] 和 arr[mid+1...r]两部分进行归并
template <typename T>
void __merge2(T arr[], int l, int mid, int r){

	//T aux[r-l+1];
	T *aux = new T[r-l+1];
	for (int i = l; i <= r; i++)
	{
		aux[i-l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i  > mid){
			arr[k] = aux[j-l];
			j++;
		}
		else if (j > r){
			arr[k] = aux[i - l];
			i++;
		}
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

	//delete(aux);
	delete[] aux;
}


//递归使用归并排序,对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort02(T arr[],int l,int r){

	/*
	if (l >= r)
	{
		return;
	}
	*/
	if ( r - l <= 15)
	{
		insertionSort03(arr, l, r);
		return;
	}
	

	int mid = (l + r) / 2;
	__mergeSort02(arr, l, mid);
	__mergeSort02(arr, mid + 1, r);
	//if(arr[mid] <= arr[mid+1])
	if (arr[mid] > arr[mid+1])
	{
		__merge2(arr, l, mid, r);
	}
	
}

template <typename T>
void mergeSort02(T arr[],int n)
{
	__mergeSort02(arr,0,n-1);
}

#endif //CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_HinsertionSort03