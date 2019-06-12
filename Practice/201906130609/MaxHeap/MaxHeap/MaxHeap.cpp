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

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	cout << maxHeap.size() << endl;

	return 0;
}

