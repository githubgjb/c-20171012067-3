// SortTestHelper.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "sortTestHelper.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	int *arr = sortTestHelper::generateRandomArray(n,0,n);
	sortTestHelper::printArray(arr,n);

	delete(arr);
	return 0;
}

