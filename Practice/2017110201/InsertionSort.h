

template<typename T>
void insertionSort(T arr[] ,int n){
	for(int i=1 ; i < n ;i++){
		
		for(int j = i ; j>0 ;j--){
			if(arr[j]<arr[j-1]){
				swap(arr[j],arr[j-1]);
			}else{
				break;
			}
		}
	}
} 


template<typename T>
void InsertionSort(T arr[],int n){	
	for(int i=1 ; i < n ; i++){
		T e = arr[i];
		int j;
		for(j = i ;j>0 && arr[j-1] > e ; j-- ){
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}

template<typename T>
void InsertionSort(T arr[], int n){
	for(int i=1 ; i<n ; i++){
		
		T e = arr[i];
		int j;
		for(j=i ; j>0 && arr[j-1] > e ; j-- ){
			arr[j] = arr[j-1];
		}
		arr[j] = e;		
	}	
}


template<typename T>
void InsertSort(T arr[],int n){
	
	for(int i=1 ;i<n ;i++){
		T e = arr[i];		
		int j;
		for(int j=i;i>0 && arr[j-1] > e ;j--){
			arr[j] = arr[j-1];
		}
		arr[j] = e; 
	}	
}

template<typename T>
void insertionSort(T arr[] , int n){
	
	for(int i = 1 ; i < n ; i++ ){
		
		T e = arr[i];
		int j;
		for(j=i ; j>0 && arr[j-1] > e ; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = e;
	}
}


void SelectionSort(int arr[] , int n){
	
	for(int i=0 ;i < n ;i++){
		
		int minIndex = i;
		for(int j= i+1 ;j<n ;j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}			
		}
		swap(arr[i],arr[minIndex]);
	}
	
	
}




























