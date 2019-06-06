#include "mergeSort02.h"

template <typename T>
void mergeSortBU(T arr[],int n){

	//2 4 8 16 32
	for (int  sz = 1; sz <= n ; sz += sz)
	{
		/*
		//有边界问题
		for (int  i = 0; i < n; i += sz + sz)
		{
			//对arr[i...i+sz-1]和arr[i + sz...i +  sz + sz - 1]  进行归并
			__merge2(arr, i, i + sz - 1, i + sz + sz - 1);
		}
		*/
		//没有优化
		//优化点1.小到一定程度用插入排序.2,不是每次都需要merge,对近乎有序的数组
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			//对arr[i...i+sz-1]和arr[i + sz...i +  sz + sz - 1]  进行归并
			__merge2(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}

}