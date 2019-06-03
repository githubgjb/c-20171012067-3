
#include <iostream>
#include <cassert>
#include <ctime>
#include <algorithm>

using namespace std;

namespace sortTestHelper{

	//���ɴ�СΪn,��Χ��[rangeL,rangeR]��Χ�ڵ��������
	int* generateRandomArray(int n,int rangeL,int rangeR){

		assert(rangeL<rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR-rangeL+1)+rangeL;
		}
		return arr;
	}

	template<typename T>
	void printArray(T arr[],int n){
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

}