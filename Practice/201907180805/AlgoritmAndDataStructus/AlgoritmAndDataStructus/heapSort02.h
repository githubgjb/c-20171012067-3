#include <iostream>
#include <algorithm>

using namespace std;
template<typename T>
void heapSort02(T arr[], int n){
	MaxHeap<T> maxHeap = MaxHeap<T>(arr,n);
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxHeap.extractMax();
	}
}