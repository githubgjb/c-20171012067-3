#include <iostream>
#include <algorithm>
using namespace std;


template <typename T>
void insertionSort(T arr[],int n){

	for (int i = 1; i < n; i++)
	{
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		/*
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
		*/
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
		{
			swap(arr[j], arr[j - 1]);
		}
	}

}
