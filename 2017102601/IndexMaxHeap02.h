
//索引堆 (索引:值)
//0       1  2  3  4  5  6  7  8  9  10
//index  10  9  7  8  5  6  3  1  4   2
//data   15 17 19 13 22 16 28 30 41  62 
//rev     8 10  7  9  5  6  3  4  2   1

//i这个索引在数组中的位置

//reverse[i] 表示索引i在indexes(堆)中的位置


//indexes[i] = j;
//reverse[j] = i;

//indexes[reverse[i]] = i;
//reverse[indexes[i]] = i;

//举例
//reverse[4] = 9;
//indexes[9] = 4;
//data[4] = 13;

template<typename Item>
class IndexMaxHeap{

private:
	Item* data;
	int* indexes;//索引 
	int* reverse;//反向查找 
	
	int count;
	int capacity;
	
	void shiftUp(int k){
		
		//这个节点的父节点是否比当前值小
		/*
		while(k >1 && data[k/2] < data[k]){
		    swap(data[k/2],data[k]);
			k /= 2;//更新一下索引K
		}
		*/
		
		while(k >1 && data[indexes[k/2]] < data[indexes[k]]){
		    swap(indexes[k/2],indexes[k]);
			reverse[indexes[k/2]] = k/2;
			reverse[indexes[k]] = k;
			
			k /= 2;//更新一下索引K
		}
	}
	void shiftDown(int k){
		//在完全二叉树有有右孩子,一定有孩子
		/*
		while(2*k <= count){
			int j = 2*k; 
			//在此轮循环中,data[k]和data[j]交换位置
			//有右孩子         右孩子大于左孩子
			if(j+1 <= count && data[j+1] > data[j]){
				j += 1;
			}
			if(data[k] >= data[j]){
				break;
			}
			swap(data[k],data[j]);
			k = j;
		}
		*/
		
		//在完全二叉树有有右孩子,一定有孩子
		while(2*k <= count){
			int j = 2*k; 
			//在此轮循环中,data[k]和data[j]交换位置
			//有右孩子         右孩子大于左孩子
			if(j+1 <= count && data[indexes[j+1]] > data[indexes[j]]){
				j += 1;
			}
			if(data[indexes[k]] >= data[indexes[j]]){
				break;
			}
			swap(indexes[k],indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	}
	
public:
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		reverse = new int[capacity + 1];
		
		//i这个索引在堆中根本就不存在
		for(int i=0 ; i <= capacity; i++){
			reverse[i] = 0;
		}
		
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap(Item arr[],int n){
		
		data = new Item[n+1];
		capacity = n;
		for(int i=0 ; i < n ; i++){
			data[i+1] = arr[i];
		}
		count = n;
		
		//从第一个不是叶子的节点开始
		for(int i = count/2; i >= 1 ; i--){
			shiftDown(i);
		}
		
	}
	
	~MaxHeap(){
		delete [] data;
		delete [] indexes;
		delete [] reverse;
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	//传入的i对用户而言,是从0索引的
	void insert(int i,Item item){
		
		assert(count+1 <= capacity);
		assert(i+1 >= 1 && i+1 <= capacity);
		
		i += 1;
		//data[count+1] = item;
		data[i] = item;
		indexes[count+1] = i;
		reverse[i] = count + 1;
		
		count ++;
		shiftUp( count );
	}
	
	Item extractMax(){
		
		assert(count > 0);
		
		//Item ret = data[1];
		Item ret = data[indexes[1]];
		
		//swap(data[1] , data[count]);		
		swap(indexes[1] , indexes[count]);
		reverse[indexes[1]] = 1;//最大值
		reverse[indexes[count]] = 0;//减少一个容量
		
		
		count --;
		shiftDown(1);
		
		return ret;
		
	}
	
	int extractMaxIndex(){
		
		assert(count > 0);
		
		//Item ret = data[1];
		int ret = indexes[1] - 1;//从外部用户索引是从0开始的
		
		//swap(data[1] , data[count]);		
		swap(indexes[1] , indexes[count]);
		reverse[indexes[1]] = 1;//最大值
		reverse[indexes[count]] = 0;//减少一个容量
		
		
		
		count --;
		shiftDown(1);
		
		return ret;
		
	}
	
	bool contain(int i){
		assert( i+1 >= 0 && i + 1 <= capacity);
		return reverse[i+1] != 0;
		
	}
	
	Item getItem(int i){
		assert(contain(i));
		return data[i+1];
	}
	
	//利用索引堆修改内容
	void change(int i,Item newItem){
		
		assert(contain(i));
		
		i += 1;
		data[i] = newItem;
		
		//data[i]在堆中的位置
		//找到indexes[j] = i,j表示data[i]在堆中的位置
		//之后shiftUp(j),再shiftDown(j)
		/*
		for(int j=1; j<count; j++){
			if(indexes[j] == i){
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
		*/
		//找到堆中的位置
		int j = reverse[i];
		shiftUp(j);
		shiftDown(j);						
	}
	
};


template<typename T>
void heapSort2(T arr[],int n){
	
	MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
	//从小到大
	for(int i=n-1 ; i>0 ; i--){
		arr[i] = maxheap.extractMax();
	}
	
}

template<typename T>
void __shiftDown(T arr[],int n,int k){
	
	//在完全二叉树有有右孩子,一定有孩子
	while(2*k+1 < n){
		int j = 2*k+1; 
		//在此轮循环中,arr[k]和data[j]交换位置
		//有右孩子         右孩子大于左孩子
		if(j+1 < n && arr[j+1] > arr[j]){
			j += 1;
		}
		if(arr[k] >= arr[j]){
			break;
		}
		swap(arr[k],arr[j]);
		k = j;
	}
	
}

//原地堆排序
template<typename T>
void heapSort(T arr[],int ns){
	
	//heapify 堆排序
	//从非叶子节点开始
	//从最后一个不是叶子的节点开始 从0
	//(count-1)/2
	for(int i = (n-1)/2 ; i>=0 ; i--){
		__shiftDown(arr, n , i);
	}
	
	//把最大堆,变成从小到大的数组
	for(int i = n-1;i>0;i--){
		swap(arr[0] , arr[i]);
		__shiftDown(arr,i,0);
	}
}


int main() {
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;
	
	srand(time(NULL));
	for(int i=0 ; i<15 ; i++){		
		maxheap.insert(rand()%100);	
	}
	
	while(!maxheap.isEmpty()){
		cout << maxheap.extractMax() << " ";		
	}
	cout<<endl;
	
	return 0;
}