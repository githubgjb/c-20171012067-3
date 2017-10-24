template<typename T>
void heapSort1(T arr[],int n){
	
	//把数组中的元素放入堆中用循环的方式
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i=0;i<n;i++){
		maxheap.insert(arr[i]);
	}
	
	//从小到大
	for(int i=n-1 ; i>0 ; i--){
		arr[i] = maxheap.extractMax();
	}
}

//第一个非叶子节点
//元素个数除以二,元素以1开始
//10 / 2 = 5

