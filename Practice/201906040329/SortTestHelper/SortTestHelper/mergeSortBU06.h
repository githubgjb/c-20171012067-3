#include "mergeSort02.h"

template <typename T>
void mergeSortBU06(T arr[],int n){
	for (int sz = 1; sz <= n; sz+=sz)
	{
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			//arr[i...i+sz-1] arr[i+sz...i+sz+sz]
			__merge2(arr, i, i + sz - 1, min(i + sz + sz-1, n - 1));
		}

	}
}