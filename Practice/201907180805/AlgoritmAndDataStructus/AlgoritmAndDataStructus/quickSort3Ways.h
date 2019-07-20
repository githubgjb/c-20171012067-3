#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void __insertionSortQuickSort3Ways(T arr[], int l, int r){

	for (int i = l + 1; i <= r; i++)
	{
		//寻找元素arr[i]合适的插入位置
		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

/*
	arr[l...r]
	arr[l...r] < v ==v > v
	<v >v
*/
template<typename T>
void __quickSort3Ways(T arr[],int l,int r){
	if ( r - l <= 15)
	{
		__insertionSortQuickSort3Ways(arr, l, r);
		return;
	}

	//partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int lt = l;
	int gt = r + 1;
	int i = l + 1;
	while ( i < gt )
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v){
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else{ //arr[i] == v
			i++;
		}

	}
	swap(arr[l],arr[lt]);
	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[],int n){
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}
