
                   //要排序的数组,数组中的个数
void SelectionSort(int arr[] , int n){
	for(int i=0 ; i<n ; i++){
		int minIndex = i;
		for(int j = i+1 ; j<n ; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[i] , arr[minIndex]);
	}	
}

void SelectionSort(int arr[],int n){
	
	for(int i=0; i<n ;i++){
		int minIndex = i;
		for(int j = i+1 ; j<n ; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(arr[i] , arr[minIndex]);
	}	
}





















