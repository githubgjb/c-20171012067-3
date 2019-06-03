// TestSortHelper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "testSortHelper.h"
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000;
	int *arr = testSortHelper::generateRandomArray(n,0,n);
	testSortHelper::printArray(arr,n);
	delete(arr);
	return 0;
}

