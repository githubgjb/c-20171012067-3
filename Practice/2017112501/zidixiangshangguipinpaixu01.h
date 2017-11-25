
using namespace std;


template <typename T>
void mergeSortBU(T arr[],int n){
	
	//自身乘以2
	for(int sz = 1 ; sz <= n ; sz += sz){
		
		//归并的启始位置
		for( int i = 0 ; i + sz < n ; i += sz + sz){
			//对arr[i...i+sz-1] 和 [i+sz ..i+2*sz-1]
			__merge(arr,i,i+sz-1, min(i + sz + sz -1,n-1));
		}
	}
	
}

int main(){
	
	
	return 0;
}