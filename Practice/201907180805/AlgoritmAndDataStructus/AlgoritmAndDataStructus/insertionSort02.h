
#include <iostream>
#include <algorithm>

using namespace std;
template<typename T>
void insertionSort02(T arr[], int n){

	for (int i = 1; i < n; i++)
	{
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		T e = arr[i];
		int j;
		for (j = i; j > 0 && arr[j-1] > e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}

}