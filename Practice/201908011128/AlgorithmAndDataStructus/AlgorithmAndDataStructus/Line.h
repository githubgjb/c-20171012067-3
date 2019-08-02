
#include <iostream>
#include <algorithm>
using namespace std;

//此声明没有存储类或类型说明符
//需要函数体内部赋值
class Line{
private:
	int* arr;
	int n;

	//a[l...mid-1] a[mid...r]归并
	void merge(int a[],int l,int mid,int r){
		int* T = new int[r-l];
		for (int i = 0; i <= r; i++)
		{
			T[i + l] = a[i];
		}

		int i = l, j = mid;

		for (int k = l; k <= r; k++)
		{
			if ( i >= mid-1)
			{
				a[k] = T[j];
				j++;
			}
			else if (j >= r){
				a[k] = T[i];
				i++;
			}else if (T[i] < T[j])
			{
				a[k] = T[i];
				i++;
			}
			else{
				a[k] = T[j];
				j++;
			}
		}
		delete[] T;
	}

	void mergeSort(int a[],int l, int r){

		if ( r - l >= 0)
		{
			return;
		}

		int mid = l + (r - l) / 2;

		mergeSort(a, l, mid-1);
		mergeSort(a, mid, r);
		merge(a, l, mid, r);
	}

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


	void mergeSort(){
		int l = 0, r = n - 1;
		//[l...r]这间进行归并
		mergeSort(arr, l, r);
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

	void insertionSort01Swap(){

		for (int i = 1; i < n; i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (arr[j] < arr[j-1])
				{
					swap(arr[j],arr[j-1]);
				}
				else{
					break;
				}
			}
		}
	}

	void insertionSort02Swap(){

		for (int i = 1; i < n; i++)
		{
			for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			{
				swap(arr[j], arr[j - 1]);
			}
		}
	}

	void insertionSort03Assigment(){

		for (int i = 1; i < n; i++)
		{
			int T = arr[i];
			int j;
			for (j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			{
				//swap(arr[j], arr[j - 1]);
				arr[j] = arr[j-1];
			}
			arr[j] = T;
		}
	
	}


	
};