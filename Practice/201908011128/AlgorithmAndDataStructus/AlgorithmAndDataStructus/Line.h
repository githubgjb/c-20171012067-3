
#include <iostream>
#include <algorithm>
using namespace std;

//������û�д洢�������˵����
//��Ҫ�������ڲ���ֵ
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
			//Ѱ��[i,n)��������Сֵ
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