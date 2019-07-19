
#include <iostream>
#include <algorithm>

using namespace std;

//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename T>
void __merge02(T arr[], int l, int mid, int r){
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

//�ݹ�ʹ�ù鲢����,��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort02(T arr[], int l, int r){

	if (l >= r)
	{
		return;
	}
	//int mid = (l + r) / 2;
	int mid = l + (r - l) / 2;
	__mergeSort02(arr, l, mid);
	__mergeSort02(arr, mid + 1, r);
	if (arr[mid] > arr[mid+1])
	{
		__merge02(arr, l, mid, r);
	}
}

template<typename T>
void mergeSort02(T arr[], int n){
	__mergeSort02(arr, 0, n - 1);
}
