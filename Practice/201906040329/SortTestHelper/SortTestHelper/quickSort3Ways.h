
#include <algorithm>

#include "insertionSort03.h"

using namespace std;

//��·����������arr[l...r]
//��arr[l...r]��Ϊ <v ; ==v ; > v������
//֮��ݹ�� <v ; >v �����ּ���������·��������
template <typename T>
void __quickSort3Ways(T arr[],int l,int r){

	if (r - l <= 15)
	{
		insertionSort03(arr, l, r);
		return;
	}
	//partition
	swap(arr[l], arr[rand() % (r-l+1) + l]);
	T v = arr[l];

	int lt = l;     //arr[l+1...lt] < v
	int gt = r + 1; //arr[gt...r]   > v
	int i = l + 1;  //arr[lt+1...i] ==v
	while (i < gt)
	{

		if (arr[i] < v){
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}else if (arr[i] > v){
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else{ //arr[i] == v
			i++;
		}
	}
	swap(arr[l], arr[lt]);

	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template <typename T>
void  quickSort3Ways(T arr[],int n){
	srand(time(NULL));
	__quickSort3Ways(arr, 0, n - 1);
}



