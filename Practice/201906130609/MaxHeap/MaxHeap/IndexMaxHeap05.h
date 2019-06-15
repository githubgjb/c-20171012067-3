#ifndef CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_IndexMaxHeap05
#define CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H_IndexMaxHeap05

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class IndexMaxHeap05{
private:
	Item* data;
	int* indexes;
	int count;
	int capacity;

	void shiftUp(int k){

		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]])
		{
			swap(indexes[k / 2], indexes[k]);
			k /= 2;
		}
	}

	void shiftDown(int k){

		while (2 * k <= count)
		{
			int j = 2 * k; //在此轮循环中,data[k]和data[j]交换位置
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
			{
				j += 1;
			}
			if (data[indexes[k]] >= data[indexes[j]])
			{
				break;
			}
			swap(indexes[k], indexes[j]);
			k = j;

		}
	}

public:
	IndexMaxHeap05(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	

	~IndexMaxHeap05(){
		delete[] data;
		delete[] indexes;
	}
	int size(){
		return count;
	}
	bool isEmpty(){
		return count == 0;
	}

	//传入的i对用户而言,是从0索引的
	void insert(int i,Item item){

		assert(count + 1 <= capacity);
		assert(i+1 >= 1 && i+1 <= capacity);

		i += 1;
		data[i] = item;
		indexes[count + 1] = i;

		count++;
		shiftUp(count);
	}

	Item extractMax(){

		assert(count > 0);
		Item ret = data[indexes[1]];

		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);

		return ret;
	}

	int extractMaxIndex(){

		assert(count > 0);
		int ret = indexes[1] - 1;

		swap(indexes[1], indexes[count]);
		count--;
		shiftDown(1);

		return ret;
	}

	Item getItem(int i){
		return data[i + 1];
	}

	void change(int i,Item newItem) {
		i += 1;
		data[i] = newItem;

		//找到indexes[j] = i,j表示data[i]在堆中的位置
		//之后shiftUp(j),再shiftDown(j)
		for (int  j = 1; j <= count; j++)
		{
			if (indexes[j] == i)
			{
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}



	}

};

#endif //CHAPTER_03_COMPLETED_CODE_INSERTIONSORT_H