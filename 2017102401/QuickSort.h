//Partition  分割


//对arr[l...r]部分进行partition操作
//返回p,使得arr[l...p-1] < arr[p]
//          arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[],int l,int r){
	
	T v = arr[l];
	//arr[l+1...j] < v;arr[j+1...i） > v
	
	int j = l;
	for(int i=l+1 ; i <= r; i++){
		if(arr[i] < v){
			swap( arr[j+1] , arr[i] );
			j ++;
			
			//swap( arr[++j] , arr[i] );
		}
		
	}
	swap( arr[l] , arr[j] );
	
	return j;
}

//对arr[l...r]部分进行快速排序
template <typename T>
void __quickSort(T arr[],int l,int r){
		
	//到底的情况
	if(l>r){
		return;
	}
	
	int p = __partition(arr,l,r);
	__quickSort(arr,l,p-1);
	__quickSort(arr,p+1,r);
		
}


template <typename T>
void quickSort(T arr[],int n){
		__quickSort(arr,0,n-1)	
}