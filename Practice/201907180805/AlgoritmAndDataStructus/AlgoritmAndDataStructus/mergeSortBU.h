
#include <iostream>
#include <algorithm>

using namespace std;

//将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __mergeSortBUmerge(T arr[], int l, int mid, int r){
	T *aux = new T[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		else if (aux[i - l] < aux[j - l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}

	}
	delete[] aux;
}


template<typename T>
void mergeSortBU(T arr[],int n){

	for (int sz = 1; sz <= n; sz += sz)
	{
		//for (int i = 0; i < n; i += sz + sz)
		for (int i = 0; i + sz < n; i += sz + sz)
		{
			//对arr[i...i+sz-1] arr[i+sz...i+2*sz-1] merge
			//__mergeSortBUmerge(arr , i ,i + sz - 1 ,i + sz + sz -1);
			__mergeSortBUmerge(arr, i, i + sz - 1,min(i + sz + sz - 1,n-1));
		
		}
	}
}