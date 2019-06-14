
#include <algorithm>
#include "MaxHeap03.h"

using namespace std;

template <typename T>
void heapSort01(T arr[],int n){

	MaxHeap03<T> maxHeap = MaxHeap03<T>(n);
	for (int  i = 0; i < n; i++)
	{
		maxHeap.insert(arr[i]);
	}

	for (int  i = n-1; i >= 0; i--)
	{
		arr[i] = maxHeap.extractMax();
	}
	
}
