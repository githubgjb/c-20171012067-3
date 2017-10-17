//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_04_COMPLETED_CODE_HEAPSORT_H
#define CHAPTER_04_COMPLETED_CODE_HEAPSORT_H

#include <iostream>
#include <algorithm>

// �Ż���shiftDown����, ʹ�ø�ֵ�ķ�ʽȡ�����ϵ�swap,
// ���Ż�˼�������֮ǰ�Բ�����������Ż���˼·��һ�µ�
template<typename T>
void __shiftDown(T arr[], int n, int k){

	T e = arr[k];
	while (2 * k + 1 < n){
		int j = 2 * k + 1;
		if (j + 1 < n && arr[j + 1] > arr[j])
			j += 1;

		if (e >= arr[j]) break;

		arr[k] = arr[j];
		k = j;
	}

	arr[k] = e;
}

// ��ʹ��һ�����������, ֱ����ԭ�����Ͻ���ԭ�صĶ�����
template<typename T>
void heapSort(T arr[], int n){

	// ע�⣬��ʱ���ǵĶ��Ǵ�0��ʼ������
	// ��(���һ��Ԫ�ص�����-1)/2��ʼ
	// ���һ��Ԫ�ص����� = n-1
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		__shiftDown2(arr, n, i);

	for (int i = n - 1; i > 0; i--){
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}

using namespace std;

#endif //CHAPTER_04_COMPLETED_CODE_HEAPSORT_H
