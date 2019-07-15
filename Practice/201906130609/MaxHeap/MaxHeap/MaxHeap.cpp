// MaxHeap.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <time.h>
#include "MaxHeap.h"
#include "MaxHeap02.h"
#include "MaxHeap03.h"
#include "sortTestHelper.h"
#include "mergeSort02.h"
#include "mergeSortBU11.h"
#include "quickSort14.h"
#include "quickSort3Ways.h"
#include "HeapSort01.h"
#include "HeapSort02.h"
#include "HeapSort03.h"
#include "BST02.h"
#include "SequenceST.h"
#include "FileOps.h"
#include "BinarySearch.h"
#include "BST06.h"
#include "MaxHeap05.h"
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	MaxHeap05<int> maxheap = MaxHeap05<int>(100);

	cout << maxheap.size() << endl;
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		maxheap.insert(rand() % 100);
	}
	cout << maxheap.size() << endl;

	/*
	// ����ʹ���ı�����С�Ĺ����������Խ�������:)
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// ����1, ���ǰ����ı�ԭ��˳����������������
		time_t startTime = clock();
		BST06<string, int> *bst = new BST06<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst).search(*iter);
			if (res == NULL)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (bst->contain("unite"))
			cout << "'unite' : " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;


		// ����2, ���ǰ����ı�ԭ��˳�����˳����ұ�
		startTime = clock();
		SequenceST<string, int> *sst = new SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*sst).search(*iter);
			if (res == NULL)
				(*sst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (sst->contain("unite"))
			cout << "'unite' : " << *(*sst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete sst;


	}
	*/
	/*---------------------------------------------------------*/

	/*

	// ����ʹ���ı�����С�Ĺ����������Խ�������:)
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words)) {

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// ����1, ���ǰ����ı�ԭ��˳����������������
		time_t startTime = clock();
		BST02<string, int> *bst = new BST02<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst).search(*iter);
			if (res == NULL)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (bst->contain("unite"))
			cout << "'unite' : " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;


		// ����2, ���ǰ����ı�ԭ��˳�����˳����ұ�
		startTime = clock();
		SequenceST<string, int> *sst = new SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*sst).search(*iter);
			if (res == NULL)
				(*sst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (sst->contain("unite"))
			cout << "'unite' : " << *(*sst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete sst;


		// ����3, ���ǽ�ԭ�ı������������������, �鿴��Ч��
		startTime = clock();
		BST02<string, int> *bst2 = new BST02<string, int>();

		sort(words.begin(), words.end());
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int *res = (*bst2).search(*iter);
			if (res == NULL)
				(*bst2).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		cout << "'unite' : " << *(*bst2).search("unite") << endl;
		endTime = clock();

		cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst2;
	}
	*/



	/*----------------------------------------------------------*/


	/*
	int n = 1000000;
	// ����1 һ�����
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int *arr1 = sortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = sortTestHelper::copyIntArray(arr1, n);
	int *arr3 = sortTestHelper::copyIntArray(arr1, n);
	int *arr4 = sortTestHelper::copyIntArray(arr1, n);
	int *arr5 = sortTestHelper::copyIntArray(arr1, n);
	int *arr6 = sortTestHelper::copyIntArray(arr1, n);

	//todo
	sortTestHelper::testSort("Merge02 Sort",mergeSort02,arr1,n);
	sortTestHelper::testSort("quickSort14 Sort", quickSort14, arr2, n);
	sortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	sortTestHelper::testSort("heapSort01 Sort", heapSort01, arr4, n);
	sortTestHelper::testSort("heapSort02 Sort", heapSort02, arr5, n);
	sortTestHelper::testSort("heapSort03 Sort", heapSort03, arr6, n);

	delete(arr1);
	delete(arr2);
	delete(arr3);
	delete(arr4);
	delete(arr5);
	delete(arr6);

	cout << endl;

	// ����2 ���Դ��ڰ���������ͬԪ�ص�����
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = sortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = sortTestHelper::copyIntArray(arr1, n);
	arr3 = sortTestHelper::copyIntArray(arr1, n);
	arr4 = sortTestHelper::copyIntArray(arr1, n);
	arr5 = sortTestHelper::copyIntArray(arr1, n);
	arr6 = sortTestHelper::copyIntArray(arr1, n);

	//todo
	sortTestHelper::testSort("Merge02 Sort", mergeSort02, arr1, n);
	sortTestHelper::testSort("quickSort14 Sort", quickSort14, arr2, n);
	sortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	sortTestHelper::testSort("heapSort01 Sort", heapSort01, arr4, n);
	sortTestHelper::testSort("heapSort02 Sort", heapSort02, arr5, n);
	sortTestHelper::testSort("heapSort03 Sort", heapSort03, arr6, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	delete[] arr5;
	delete[] arr6;


	cout << endl;


	// ����3 ���Խ������������
	int swapTimes = 100;
	//int swapTimes = 0;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = sortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = sortTestHelper::copyIntArray(arr1, n);
	arr3 = sortTestHelper::copyIntArray(arr1, n);
	arr4 = sortTestHelper::copyIntArray(arr1, n);
	arr5 = sortTestHelper::copyIntArray(arr1, n);
	arr6 = sortTestHelper::copyIntArray(arr1, n);

	//todo
	sortTestHelper::testSort("Merge02 Sort", mergeSort02, arr1, n);
	sortTestHelper::testSort("quickSort14 Sort", quickSort14, arr2, n);
	sortTestHelper::testSort("quickSort3Ways Sort", quickSort3Ways, arr3, n);
	sortTestHelper::testSort("heapSort01 Sort", heapSort01, arr4, n);
	sortTestHelper::testSort("heapSort02 Sort", heapSort02, arr5, n);
	sortTestHelper::testSort("heapSort03 Sort", heapSort03, arr6, n);

	delete(arr1);
	delete(arr2);
	delete(arr3);
	delete(arr4);
	delete(arr5);
	delete(arr6);

	cout << endl;
	*/

	//MaxHeap<int> maxHeap = MaxHeap<int>(100);
	//cout << maxHeap.size() << endl;

	/*
	MaxHeap02<int> maxHeap02 = MaxHeap02<int>(100);
	cout << maxHeap02.size() << endl;

	srand(time(NULL));
	for (size_t i = 0; i < 15; i++)
	{
		maxHeap02.insert(rand() % 100);
	}
	*/

	/*
	MaxHeap03<int> maxHeap03 = MaxHeap03<int>(100);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		maxHeap03.insert(rand() % 100);
	}
	while (!maxHeap03.isEmpty())
	{
		cout << maxHeap03.extractMax() << " ";
	}
	cout << endl;
	*/

	return 0;
}

