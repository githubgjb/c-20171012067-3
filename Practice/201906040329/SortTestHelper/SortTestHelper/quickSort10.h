
#include <algorithm>

using namespace std;


template <typename T>
int __partition10(T arr[],int l,int r){
	T v = arr[l];
	int j = l;
	// <v  >v

	//todo
	for (int i = l+1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}

	}
	swap(arr[l], arr[j]);
	return j;

}

template <typename T>
void __quickSort10(T arr[],int l,int r){

	if (l >= r)
	{
		return;
	}
	int p = __partition10(arr, l, r);
	__quickSort10(arr, l, p - 1);
	__quickSort10(arr, p + 1, r);

}


template <typename T>
void quickSort10(T arr[],int n){
	__quickSort10(arr, 0, n - 1);
}