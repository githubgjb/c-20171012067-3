
#include <algorithm>

#include "insertionSort03.h"

using namespace std;

/*
双路快排
*/

//对arr[l...r]部分进行partition操作
//返回,使得[l...p-1] < arr[p]
//arr[p+1...r] > arr[p]

template <typename T>
int __partition12(T arr[], int l, int r){

	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];

	//arr[l+1...i) <= v; arr(j...r] >=v
	int i = l + 1, j = r;
	//todo
	while (true)
	{
		while (i <= r && arr[i] < v) i++;
		while (j >= l+1 && arr[j] > v ) j--;
		if (i > j) break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	swap(arr[l], arr[j]);
	return j;
}

template <typename T>
void __quickSort12(T arr[], int l, int r){

	/*
	if (l >= r)
	{
	return;
	}
	*/
	if (r - l <= 15)
	{
		insertionSort03(arr, l, r);
		return;
	}


	int p = __partition12(arr, l, r);
	__quickSort12(arr, l, p - 1);
	__quickSort12(arr, p + 1, r);

}


template <typename T>
void quickSort12(T arr[], int n){
	srand(time(NULL));
	__quickSort12(arr, 0, n - 1);
}