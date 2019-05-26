// MargeSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include "SortTestHelper.h"
using namespace std;

//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
//�ϲ�
template<typename T>
void __merge(T arr[], int l,int mid, int r){

	//Ϊʲô��1��Ϊ�Ǳ�����,�ٻ��ɿ�����
	//T aux[r - l + 1];
	T *aux = new T[r - l + 1];
	//copy
	for (int i = l; i <= r; i++)
	{
		aux[i - l] = arr[i];
	}

	//���������鿪ͷ��λ��
	int i = l, j = mid + 1;
	for (int  k = l; k <= r; k++)
	{
		//����Խ������
		//arr[l...mid]
		if (i > mid)
		{
			arr[k] = aux[j - l];
			j++;
		}
		//arr[mid+1...r]
		else if (j > r)
		{
			arr[k] = aux[i - l];
			i++;
		}
		//һ�����
		//ע����ƫ��
		else if (aux[i-l] < aux[j-l])
		{
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}



}

//�ݹ�ʹ�ù鲢����,��arr[l....r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l,int r){

	//�ݹ鵽�׵����
	if (l >= r)
	{
		return;
	}
	int mid = (l + r) / 2; //��bug
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid + 1, r);

	//�����ν���merge
	__merge(arr,l,mid,r);
}

template<typename T>
void mergeSort(T arr[], int n){

	//ǰ�Ϻ��[]
	__mergeSort(arr,0,n-1);

}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 500000;
	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);

	delete[] arr1;

	cout << endl;

	return 0;
}

