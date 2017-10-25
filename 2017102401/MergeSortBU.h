

//将arr[l..mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[],int l,int mid,int r){
	
	T aux[r-l+1];
	for(int i = l; i<=r ;i++){
		aux[i-l] = arr[i];		
	}
	int i = l,j = mid + 1;
	for(int k=l ; k<=r ; k++){
		
		if( i > mid){
			arr[k] = aux[j-l];
			j++;
		}
		else if(j > r){
			arr[k] = aux[i-l]
			i++
		}
		//以上是判断索引合法性,下面才是
		else if(aux[i-l]<aux[j-l]){
			arr[k] = aux[i-l];
			i++;
		}else{
			arr[k] = aux[j-l];
			j++;
		}		
	}
}



//递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[],int l,int r){
	
	if(l >= r){
		return;		
	}
	
	//把数组分成两半
	int mid = (l+r)/2;
	__mergeSort(arr,l,mid);
	__mergeSort(arr,mid+1,r);
	__merge(arr,l,mid,r)
}



template<typename T>
void mergeSort(T arr[],int n){
	
	__mergeSort(arr,0,n-1);
}


//通过索引直接获取元素
//进行自底向上的归并
void mergeSortBU(T arr[],int n){
	
	for(int sz=1 ; sz <= n ; sz += sz ){
		//for(int i=0; i<n ;i += sz+sz){
		for(int i=0; i + sz <n ;i += sz+sz){	
			//对 arr[i...i_sz-1]和 arr[i+sz...i+2*sz-1进行归并]
			//__merge(arr , i, i + sz -1 , i + sz + sz -1);
			__merge(arr , i, i + sz -1 , min(i + sz + sz -1,n-1));
			
		}		
	}	
}


