
using namespace std;

template <typename T>
void insertionSort07(T arr[],int n){

	for (int i = 1; i < n; i++)
	{
		//arr[i]���ʵĲ���λ��
		T e = arr[i];
		int j;

		for ( j = i; j > 0 && arr[j-1] > e; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}

}