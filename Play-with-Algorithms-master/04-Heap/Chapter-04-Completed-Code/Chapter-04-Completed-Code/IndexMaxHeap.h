//
// Created by liuyubobobo on 4/25/17.
//

#ifndef CHAPTER_04_COMPLETED_CODE_INDEXMAXHEAP_H
#define CHAPTER_04_COMPLETED_CODE_INDEXMAXHEAP_H

#include <iostream>
#include <algorithm>

using namespace std;

// ���������
template<typename Item>
class IndexMaxHeap{

private:
	Item *data;     // ����������е�����
	int *indexes;   // ����������е�����, indexes[x] = i ��ʾ����i��x��λ��
	int *reverse;   // ����������еķ�������, reverse[i] = x ��ʾ����i��x��λ��

	int count;
	int capacity;

	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftUp(int k){

		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]]){
			swap(indexes[k / 2], indexes[k]);
			reverse[indexes[k / 2]] = k / 2;
			reverse[indexes[k]] = k;
			k /= 2;
		}
	}

	// ��������, ����֮��ıȽϸ���data�Ĵ�С���бȽ�, ��ʵ�ʲ�����������
	void shiftDown(int k){

		while (2 * k <= count){
			int j = 2 * k;
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])
				j += 1;

			if (data[indexes[k]] >= data[indexes[j]])
				break;

			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	}

public:
	// ���캯��, ����һ���յ�������, ������capacity��Ԫ��
	IndexMaxHeap(int capacity){

		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		for (int i = 0; i <= capacity; i++)
			reverse[i] = 0;

		count = 0;
		this->capacity = capacity;
	}

	~IndexMaxHeap(){
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	// �����������е�Ԫ�ظ���
	int size(){
		return count;
	}

	// ����һ������ֵ, ��ʾ���������Ƿ�Ϊ��
	bool isEmpty(){
		return count == 0;
	}

	// ������������в���һ���µ�Ԫ��, ��Ԫ�ص�����Ϊi, Ԫ��Ϊitem
	// �����i���û�����,�Ǵ�0������
	void insert(int i, Item item){
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1 && i + 1 <= capacity);

		// �ٲ���һ����Ԫ��ǰ,����Ҫ��֤����i���ڵ�λ����û��Ԫ�صġ�
		assert(!contain(i));

		i += 1;
		data[i] = item;
		indexes[count + 1] = i;
		reverse[i] = count + 1;
		count++;

		shiftUp(count);
	}

	// �������������ȡ���Ѷ�Ԫ��, �������������洢���������
	Item extractMax(){
		assert(count > 0);

		Item ret = data[indexes[1]];
		swap(indexes[1], indexes[count]);
		reverse[indexes[count]] = 0;
		reverse[indexes[1]] = 1;
		count--;
		shiftDown(1);
		return ret;
	}

	// �������������ȡ���Ѷ�Ԫ�ص�����
	int extractMaxIndex(){
		assert(count > 0);

		int ret = indexes[1] - 1;
		swap(indexes[1], indexes[count]);
		reverse[indexes[count]] = 0;
		reverse[indexes[1]] = 1;
		count--;
		shiftDown(1);
		return ret;
	}

	// ��ȡ����������еĶѶ�Ԫ��
	Item getMax(){
		assert(count > 0);
		return data[indexes[1]];
	}

	// ��ȡ����������еĶѶ�Ԫ�ص�����
	int getMaxIndex(){
		assert(count > 0);
		return indexes[1] - 1;
	}

	// ������i���ڵ�λ���Ƿ����Ԫ��
	bool contain(int i){
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}

	// ��ȡ���������������Ϊi��Ԫ��
	Item getItem(int i){
		assert(contain(i));
		return data[i + 1];
	}

	// �����������������Ϊi��Ԫ���޸�ΪnewItem
	void change(int i, Item newItem){

		assert(contain(i));
		i += 1;
		data[i] = newItem;

		// �ҵ�indexes[j] = i, j��ʾdata[i]�ڶ��е�λ��
		// ֮��shiftUp(j), ��shiftDown(j)
		//        for( int j = 1 ; j <= count ; j ++ )
		//            if( indexes[j] == i ){
		//                shiftUp(j);
		//                shiftDown(j);
		//                return;
		//            }

		// ���� reverse ֮��,
		// ���ǿ��Էǳ��򵥵�ͨ��reverseֱ�Ӷ�λ����i��indexes�е�λ��
		shiftUp(reverse[i]);
		shiftDown(reverse[i]);
	}
};

#endif //CHAPTER_04_COMPLETED_CODE_INDEXMAXHEAP_H
