
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template<typename Item>
class IndexMaxHeap{
private:
	Item* data;
	int* indexes;
	int* reverse;
	int count;
	int capacity;


	void shiftUp(int k){
		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]])
		{
			swap(indexes[k / 2], indexes[k]);
			reverse[indexes[k / 2]] = k / 2;
			reverse[indexes[k]] = k;
			k /= 2;
		}
	}
	void shiftDown(int k){

		//有没有左孩子
		while (2 * k <= count)
		{
			int j = 2 * k; //此轮循环中data[k] 和data[j]交换位置
			//有没有做右孩子
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
			{
				j += 1;
			}
			//父节点比左右两结点都大结束循环
			if (data[indexes[k]] >= data[indexes[j]])
			{
				break;
			}
			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			//变了，下轮循环继续
			k = j;
		}
	}
public:
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		for (int i = 0; i <= capacity; i++)
		{
			reverse[i] = 0;
		}
		count = 0;
		this->capacity = capacity;
	}

	IndexMaxHeap(Item arr[], int n){
		data = new Item[n + 1];
		capacity = n;
		for (int i = 0; i < n; i++)
		{
			data[i + 1] = arr[i];
		}
		count = n;

		for (int i = count / 2; i >= 1; i--)
		{
			shiftDown(i);
		}

	}

	~IndexMaxHeap(){
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	int size(){
		return count;
	}

	bool isEmpty(){
		return count == 0;
	}

	void insert(int i,Item item){

		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);

		i += 1;

		data[i] = item;
		indexes[count + 1] = i;
		reverse[i] = count + 1;

		count++;
		shiftUp(count);
	}

	Item extractMax(){
		assert(count > 0);
		Item ret = data[indexes[1]];

		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);

		return ret;
	}

	int extractMax(){
		assert(count > 0);
		int ret = indexes[1] - 1;

		swap(indexes[1], indexes[count]);
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);

		return ret;
	}

	bool contain(int i){
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}

	Item getItem(int i){
		assert(contain(i));
		return data[i + 1];
	}

	void change(int i,Item newItem){

		assert( contain(i) );
		i += 1;
		data[i] = newItem;

		/*
		for (int j = 0; j <= count ; j++)
		{
			if (indexes[j] == i)
			{
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
		*/
		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);

	}
};