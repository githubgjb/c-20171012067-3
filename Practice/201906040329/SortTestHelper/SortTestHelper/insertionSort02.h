
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void insertionSort02(T arr[],int n){

	for (int i = 1; i < n; i++)
	{
		//Ѱ��arr[i]�к��ʵ�λ��
		for (int j = i; j > 0 && arr[j] < arr[j-1] ; j--)
		{
			swap(arr[j],arr[j-1]);
		}
	}

}