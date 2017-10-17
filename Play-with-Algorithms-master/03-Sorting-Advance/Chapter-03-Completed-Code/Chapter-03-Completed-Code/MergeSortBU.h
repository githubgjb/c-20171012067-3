//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_03_COMPLETED_CODE_MERGESORTBU_H
#define CHAPTER_03_COMPLETED_CODE_MERGESORTBU_H

#include <iostream>
#include <algorithm>

using namespace std;

// �Ե����ϵĹ鲢������, merge������û�иı�
// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename  T>
void __mergeBU(T arr[], int l, int mid, int r){

	//* VS��֧�ֶ�̬��������, ������ʹ�� T aux[r-l+1]�ķ�ʽ����aux�Ŀռ�
	//* ʹ��VS��ͬѧ, ��ʹ��new�ķ�ʽ����aux�ռ�
	//* ʹ��new����ռ�, ��Ҫ������__merge���������, delete������Ŀռ�:)
	//T aux[r - l + 1];
	T *aux = new T[r-l+1];

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

// ʹ���Ե����ϵĹ鲢�����㷨
template <typename T>
void mergeSortBU(T arr[], int n){

	// Merge Sort Bottom Up ���Ż��汾
	for (int sz = 1; sz < n; sz += sz)
	for (int i = 0; i < n - sz; i += sz + sz)
		// �� arr[i...i+sz-1] �� arr[i+sz...i+2*sz-1] ���й鲢
		__mergeBU(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));

}

#endif //CHAPTER_03_COMPLETED_CODE_MERGESORTBU_H
