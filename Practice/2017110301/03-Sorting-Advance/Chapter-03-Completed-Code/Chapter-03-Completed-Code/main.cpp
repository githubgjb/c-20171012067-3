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

// 比较Merge Sort, MergeSortBU; 优化过的MergeSort和MergeSortBU
// 以及三种快速排序算法的性能
int main() {

	int n = 10;

	// 测试1 一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);


	return 0;
}