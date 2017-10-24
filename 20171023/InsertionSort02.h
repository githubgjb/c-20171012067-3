
template<typename T>
void insertionSort(T arr[],int n){
	
	//第0个元素不用考虑
	for(int i=1 ; i<n ; i++){
		
		//寻找arr[i]合适的插入位置
		for(int j=i;j>0;j--){
			if(arr[j]<arr[j-1]){
				swap(arr[j],arr[j-1]);
			}else{
				break;		
			}
		}	
	}
	
}

template<typename T>
void insertionSort(T arr[],int n){
	
	//第0个元素不用考虑
	for(int i=1 ; i<n ; i++){
		
		//寻找arr[i]合适的插入位置
		for(int j=i;j>0 && arr[j]<arr[j-1]);j--){			
				swap(arr[j],arr[j-1]);			
		}	
	}
	
}

//用复制来替代交换提高性能

template<typename T>
void insertionSort(T arr[],int n){
	
	//第0个元素不用考虑
	for(int i=1 ; i<n ; i++){
		
		//寻找arr[i]合适的插入位置
		T e = arr[i];
		int j; //j保存元素e应该插入的位置
		for(j=i ; j>0 && arr[j-1] > e; j--){			
				arr[j] = arr[j-1];			
		}
		arr[j] = e;
	}
	
}
