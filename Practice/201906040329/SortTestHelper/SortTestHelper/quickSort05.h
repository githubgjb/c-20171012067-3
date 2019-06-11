
#include <algorithm>

using namespace std;

//arr[l...p-1] < arr[p]   
//arr[p] < arr[p+1....r]
template <typename T>
int __partition05(T arr[],int l,int r){
	T v = arr[l];

	//arr[l+1....j] < v
	//arr[j+1...i) >v
	int j = l;

	for (int i = l+1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[l],arr[j]);

	return j;
}

template <typename T>
void __quickSort05(T arr[],int l,int r){
	if (l>=r)
	{
		return;
	}
	int p = __partition05(arr, l, r);
	__quickSort05(arr, l, p - 1);
	__quickSort05(arr, p + 1, r);

}

template <typename T>
void quickSort05(T arr[],int n){

	__quickSort05(arr,0,n-1);
}