// MaxHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "MaxHeap.h"
#include "MaxHeap02.h"
#include "MaxHeap03.h"

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
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


	return 0;
}

