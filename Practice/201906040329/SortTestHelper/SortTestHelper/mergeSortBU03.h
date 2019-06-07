#include "mergeSort02.h"

template <typename T>
void mergeSortBU03(T arr[],int n){

	for (int sz = 1; sz <= n; sz+=sz)
	{
		for (int  i = 0; i + sz < n; i+= sz + sz)
		{
			//¶Ôarr[i...i+sz-1] arr[i+sz...i+sz+sz-1]
			__merge2(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}

	}

}