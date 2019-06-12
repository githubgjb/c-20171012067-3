// MaxHeap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap{
private:
	Item* data;
	int count;

public:
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
	}

	~MaxHeap(){
		delete[] data;
	}
	int size(){
		return count;
	}
	bool isEmpty(){
		return count == 0;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	cout << maxHeap.size() << endl;

	return 0;
}

