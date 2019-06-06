#include "mergeSort02.h"

template <typename T>
void mergeSortBU(T arr[],int n){

	//2 4 8 16 32
	for (int  sz = 1; sz <= n ; sz += sz)
	{
		/*
		//�б߽�����
		for (int  i = 0; i < n; i += sz + sz)
		{
			//��arr[i...i+sz-1]��arr[i + sz...i +  sz + sz - 1]  ���й鲢
			__merge2(arr, i, i + sz - 1, i + sz + sz - 1);
		}
		*/
		//û���Ż�
		//�Ż���1.С��һ���̶��ò�������.2,����ÿ�ζ���Ҫmerge,�Խ������������
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			//��arr[i...i+sz-1]��arr[i + sz...i +  sz + sz - 1]  ���й鲢
			__merge2(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
		}
	}

}