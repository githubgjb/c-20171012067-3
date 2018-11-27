#include <iostream>

using namespace std;
void selectionSort(int arr[],int n){

	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n ;j++){

			if (arr[j]< arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
		
	}

}

int main(){

	int a[13] = {5,3,6,2,3,5,7,8,1,2,0,3,90};

	selectionSort(a,13);

	for (int i = 0; i < 13; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	return 0;
}