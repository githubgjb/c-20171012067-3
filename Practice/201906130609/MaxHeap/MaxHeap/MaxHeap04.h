#ifndef CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_MaxHeap04
#define CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_MaxHeap04

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap04{
private:
	Item* data;
	int count;
	int capacity;

	void shiftUp(int k){

		while (k > 1 && data[k / 2] < data[k])
		{
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}

	void shiftDown(int k){

		while (2 * k <= count)
		{
			int j = 2 * k; //在此轮循环中,data[k]和data[j]交换位置
			if (j + 1 <= count && data[j + 1] > data[j])
			{
				j += 1;
			}
			if (data[k] >= data[j])
			{
				break;
			}
			swap(data[k], data[j]);
			k = j;

		}
	}

public:
	MaxHeap04(int capacity){
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap04(Item arr[],int n){

		data = new Item[n + 1];
		capacity = n;
		for (int i = 0; i < n; i++)
		{
			data[i + 1] = arr[i];
		}
		count = n;

		for (int i = count/2 ; i >= 1; i--)
		{
			shiftDown(i);
		}
	
	}

	~MaxHeap04(){
		delete[] data;
	}
	int size(){
		return count;
	}
	bool isEmpty(){
		return count == 0;
	}

	void insert(Item item){

		assert(count + 1 <= capacity);

		data[count + 1] = item;
		count++;
		shiftUp(count);
	}

	Item extractMax(){

		assert(count > 0);
		Item ret = data[1];

		swap(data[1], data[count]);
		count--;
		shiftDown(1);

		return ret;
	}


};

#endif //CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H