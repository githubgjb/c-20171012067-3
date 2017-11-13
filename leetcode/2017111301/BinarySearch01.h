
#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template<typename T>
//在arr中有n个元素中有target的值
int binarySearch( T arr[],int n,T target ){
	
	//在[l...r]的范围里寻找target
	int l = 0 ,r = n - 1; //左右两个边界
	while(l <= r){ //当 l == r 时,区间[l...r]依然是有效的
		
		int mid = (l+r)/2;
		if(arr[mid] == target){
			return mid;
		}

		if( target > arr[mid] ){//target在右侧[mid+1...r]
			l = mid + 1;			
		}else{//target在左侧[l....mid-1]  //target < arr[mid]
			r = mid - 1;
		}		
	}

	return -1;
}

int main(){
	return 0;
}