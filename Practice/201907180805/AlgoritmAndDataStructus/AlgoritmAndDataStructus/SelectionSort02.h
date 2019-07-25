
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void selectionSort02(T arr[], int n){
	for (int i = 0; i < n; i++)
	{
		//Ѱ��[i,n)���������Сֵ
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}