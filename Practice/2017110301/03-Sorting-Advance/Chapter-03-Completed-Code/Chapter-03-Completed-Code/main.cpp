#include <iostream>
#include <algorithm>
#include <ctime>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "MergeSortO.h"
#include "MergeSortBU.h"
#include "MergeSortBUO.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"

using namespace std;

// �Ƚ�Merge Sort, MergeSortBU; �Ż�����MergeSort��MergeSortBU
// �Լ����ֿ��������㷨������
int main() {

	int n = 10;

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);


	return 0;
}