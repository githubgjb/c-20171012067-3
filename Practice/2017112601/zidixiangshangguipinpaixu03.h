
using namespace std;


template <typename T>
void mergeSortBU(T arr[],int n){
	
	//对元素个数进行遍历 sz = sz + sz  1 2 4 8 16 32
	for(int sz = 1 ; sz <= n ; sz += sz){
		
		//每一轮启始的归并的位置
		//对两部分进行归并
		//
		for(int i = 0 ; i + sz < n ; i += sz + sz){
			//对 arr[i...i+sz-1]和[i+sz...i+2*sz-1] 进行归并
			__merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
		}
	}
	
}

int main(){
	
	
	return 0;
}