//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_03_COMPLETED_CODE_MERGESORT_H
#define CHAPTER_03_COMPLETED_CODE_MERGESORT_H

#include <iostream>
#include <algorithm>

using namespace std;

// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename  T>
void __merge(T arr[], int l, int mid, int r){

	//* VS��֧�ֶ�̬��������, ������ʹ�� T aux[r-l+1]�ķ�ʽ����aux�Ŀռ�
	//* ʹ��VS��ͬѧ, ��ʹ��new�ķ�ʽ����aux�ռ�
	//* ʹ��new����ռ�, ��Ҫ������__merge���������, delete������Ŀռ�:)
	//T aux[r - l + 1];
	T *aux = new T[r-l+1];

	cout << "l: " << l << " mid: " << mid << " r:" << r << endl;

	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	// ��ʼ����iָ����벿�ֵ���ʼ����λ��l��jָ���Ұ벿����ʼ����λ��mid+1
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++){

		if (i > mid){  // �����벿��Ԫ���Ѿ�ȫ���������
			arr[k] = aux[j - l]; j++;
		}
		else if (j > r){  // ����Ұ벿��Ԫ���Ѿ�ȫ���������
			arr[k] = aux[i - l]; i++;
		}
		else if (aux[i - l] < aux[j - l]) {  // ��벿����ָԪ�� < �Ұ벿����ָԪ��
			arr[k] = aux[i - l]; i++;
		}
		else{  // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
			arr[k] = aux[j - l]; j++;
		}
	}

	delete[] aux;
}

// �ݹ�ʹ�ù鲢����,��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r){

	if (l >= r)
		return;

	int mid = (l + r) / 2;

	cout << l << endl;
	cout << mid << endl;
	__mergeSort(arr, l, mid);

	cout << "------------------" << endl;
	cout << mid + 1 << endl;
	cout << r << endl;
	__mergeSort(arr, mid + 1, r);

	__merge(arr, l, mid, r);
}

// δ���Ż��Ĺ鲢�����㷨
template<typename T>
void mergeSort(T arr[], int n){

	__mergeSort(arr, 0, n - 1);
}

#endif //CHAPTER_03_COMPLETED_CODE_MERGESORT_H
