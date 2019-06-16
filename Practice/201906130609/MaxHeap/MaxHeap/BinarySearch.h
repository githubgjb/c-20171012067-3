
using namespace std;

//���ֲ��ҷ�,����������arr��,����target
//����ҵ�target,������Ӧ������index
//���û���ҵ�target,����-1
template <typename T>
int BinarySearch(T arr[],int n,T target){

	//��arr[l...r]֮�в���target
	int l = 0, r = n - 1;
	while (l <= r)
	{
		//int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}

		if (target < arr[mid])
		{
			//��arr[l...mid-1]֮�в���target
			r = mid - 1;
		}
		else//target > arr[mid]
		{
			//��arr[mid+1...r]֮�в���target
			l = mid + 1;
		}

	}

	return -1;

}


