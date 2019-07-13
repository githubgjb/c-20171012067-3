
using namespace std;

template <typename T>

int BinarySearch02(T arr[],int n,T target){
	
	int l = 0, r = n - 1;

	while ( l<=r ){
		//int mid = (l + r) / 2;

		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}

		if (target < arr[mid])
		{
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return -1;
}