#ifndef CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_heapSort02
#define CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_heapSort02

#include <algorithm>
#include "MaxHeap04.h"

using namespace std;

template <typename T>
void heapSort02(T arr[], int n){

	MaxHeap04<T> maxheap = MaxHeap04<T>(arr, n);
	//arr[1] = maxheap.extractMax();
	/*
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxHeap.extractMax();
	}
	*/
	for (int i = n-1 ; i >= 0; i--)
	{
		arr[i] = maxheap.extractMax();
	}

}

#endif //CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H