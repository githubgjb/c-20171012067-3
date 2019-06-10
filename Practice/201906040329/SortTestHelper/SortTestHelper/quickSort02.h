
#include <algorithm>

using namespace std;

//对arr[l...r]部分进行partition操作
//返回P,使得arr[l...p-1] < arr[p]  arr[p+1...r] > arr[r]
template <typename T>
int __partition02(T arr[], int l, int r){

	T v = arr[l];

	//arr[l+1....j] < v ; arr[j+1...i) > v

	int j = l;
	for (int  i = l + 1; i <= r ; i++)
	{
		//if (arr[i] > v)
		if (arr[i] < v)
		{
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}

	swap(arr[l], arr[j]);
	return j;
}

//对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort02(T arr[],int l,int r){

	if (l >= r)
	{
		return;
	}
	int p = __partition02(arr, l, r);
	__quickSort02(arr, l, p - 1);
	__quickSort02(arr, p + 1, r);


}


template <typename T>
void quickSort02(T arr[],int n){

	__quickSort02(arr, 0, n - 1);

}
