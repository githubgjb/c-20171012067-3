
template<typename T>
void __shiftDown(T arr[],int n,int k){
	
	//左孩子变成2*k+1了,从0开始
	while( 2*k+1 < n ){ //完全二叉树中,有左孩子就一定有孩子
			
		int j = 2*k + 1; //在此轮循环中,data[k]和data[j]交换位置
		
		//再判断有没有右孩子  //右孩子比左孩子大
		if(j+1 < n && arr[j+1] > arr[j]){
			j += 1;				
		}
		
		//当前元素比左孩子或右孩子都大
		if(arr[k] >= arr[j]){
			break; //可以结束循环了				
		}
		
		swap(arr[k],arr[j]);
		k = j;
	}
	
}


template<typename T>
void heapSort3(T arr[], int n){
	
	//heapify
	//索引从0开始的第一个非叶子节点的父节点
	for(int i = (n-1)/2; i >= 0; i--){
		
		//数组,多少个元素,对第i个索引
		__shiftDown(arr , n , i);
	}
	
	
	for(int i = n-1 ; i>0 ; i--){
		swap(arr[0], arr[i]);
		__shiftDown(arr,i,0);
	}
}