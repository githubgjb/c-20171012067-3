
#include <algorithm>

using namespace std;

template <typename T>
int __partition08(T arr[], int l, int r){
	// < v  > v
	T v = arr[l];
	int j = l;

	//todo
	for (int i = l+1 ; i <= r; i++)
	{
		if (arr[i] < v){
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}


	swap(arr[l], arr[j]);
	return j;
}

template <typename T>
void  __quickSort08(T arr[],int l,int r){

	if (l >= r)
	{
		return;
	}

	int p = __partition08(arr, l, r);
	__quickSort08(arr, l, p - 1);
	__quickSort08(arr, p + 1, r);
}

template <typename T>
void quickSort08(T arr[],int n){

	__quickSort08(arr, 0, n - 1);

}