//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_03_COMPLETED_CODE_MERGESORTO_H
#define CHAPTER_03_COMPLETED_CODE_MERGESORTO_H

#include <iostream>
#include <algorithm>
#include "InsertionSort.h"

using namespace std;

// �ڱ��������ܵ��Ż��Ĺ鲢������, merge������û�иı�
// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename  T>
void __mergeO(T arr[], int l, int mid, int r){

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

// ʹ���Ż��Ĺ鲢�����㷨, ��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSortO(T arr[], int l, int r){

	// �Ż�2: ����С��ģ����, ʹ�ò�������
	if (r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;
	__mergeSortO(arr, l, mid);
	__mergeSortO(arr, mid + 1, r);

	// �Ż�1: ����arr[mid] <= arr[mid+1]�����,������merge
	// ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
	if (arr[mid] > arr[mid + 1])
		__mergeO(arr, l, mid, r);
}

// �Ż��Ĺ鲢�����㷨
// �ڿγ���, ��Ҫ���ҽ����˹鲢����������Ż���
// ���ڹ鲢����ĸ����Ż�, ��ο����½ں����Ĳ�������
template<typename T>
void mergeSortO(T arr[], int n){

	__mergeSortO(arr, 0, n - 1);
}

#endif //CHAPTER_03_COMPLETED_CODE_MERGESORTO_H
