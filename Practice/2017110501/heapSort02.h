

template<typename Item>
class MaxHeap{
	
private: 
	Item* data;
	int count;
	int capacity;
	
	void shiftUp(int k){
		
		while(k > 1 && data[k/2] < data[k] ){//父节点是不是比子节点小
			swap(data[k/2],data[k]);
			//k = k/2;  //更新一下k
            k /= 2;			
		}
	}
	
	void shiftDown(int k){
		
		while( 2*k <= count ){ //完全二叉树中,有左孩子就一定有孩子
			
			int j = 2*k; //在此轮循环中,data[k]和data[j]交换位置
			
			//再判断有没有右孩子  //右孩子比左孩子大
			if(j+1 <= count  &&  data[j+1] > data[j]){
				j += 1;				
			}
			
			//当前元素比左孩子或右孩子都大
			if(data[k] >= data[j]){
				break; //可以结束循环了				
			}
			
			swap(data[k],data[j]);
			k = j;
		}		
	}
	
public:
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	
	
	//把一个堆直接构建成二叉树
	MaxHeap(Item arr[], int n){
		
		data =  new Item[n+1];
		capacity = n;
		for(int i=0 ;i < n ;i++){
			data[i+1] = arr[i];
		}
		count = n;
		
		//第一个非叶子节点的父节点
		for(int i = count/2 ; i >= 1; i--){
			shiftDown(i);			
		}		
	}

	~MaxHeap(){
		delete [] data;		
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	void insert(Item item){
		
		assert(count + 1 <= capacity);
		
		data[count+1] =  item;
		count++;
		shiftUp( count );
		
	}
	
	Item extractMax(){
		
		assert( count > 0 );
		
		Item ret = data[1];
		
		swap( data[1], data[count] );
		count --;
		
		shiftDown(1);
		
		return ret;
	}
	
};

template<typename T>
void heapSort2(T arr[], int n){
	
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for(int i = n -1; i >= 0 ;i--){
		arr[i] = maxheap.extractMax();
	}
	
}

int main(){
	
	
	return 0;
}

