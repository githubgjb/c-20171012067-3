
#include <iostream>
#include <algorithm>
using namespace std;

//此声明没有存储类或类型说明符
//需要函数体内部赋值
class Line{
private:
	int* arr;
	int n;


public:
	Line(int a[], int n){
		arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			this->arr[i] = a[i];
		}
		this->n = n;
	}
	~Line(){
		delete[] arr;
	}

	//void selectionSort(int arr[],int n){
	void selectionSort(){
		for (int i = 0; i < n; i++)
		{
			//寻找[i,n)区间里最小值
			int minIndex = i;
			for (int j = i+1; j < n; j++)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}
			swap(arr[i],arr[minIndex]);
		}

	}


	
};