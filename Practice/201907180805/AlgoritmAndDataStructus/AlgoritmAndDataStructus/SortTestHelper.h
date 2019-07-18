
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
	
	//生成有n个元素的随机数组，每个元素的随机范围[rangL,rangR]
	int* generateRandomArray(int n,int rangL,int rangR){
		assert(rangL <= rangR);
		int *arr = new int[n];
		srand(time(NULL));

		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangR - rangL + 1) + rangL;
		}

		return arr;
	}

	template<typename T>
	void parintArray(T arr[],int n){
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		return;
	}

	template<typename T>
	bool isSorted(T arr[],int n){

		for (int i = 0; i < n-1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				return false;
			}
		}
		return true;
	}

	template<typename T>
	void testSort(string sortName,void(*sort)(T[],int),T arr[],int n){
		
		clock_t startTime =  clock();
		sort(arr,n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));

		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s " << endl;
		
		return;
	}

}