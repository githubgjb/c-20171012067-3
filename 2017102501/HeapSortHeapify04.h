//Binary Heap

//索引 , 值

//left,二倍,right 二倍加一

//索引
//值

//0  1  2  3  4  5  6  7  8  9 10 
//  62 41 30 28 16 22 13 19 17 15 

//从1开始
//parent(i) = i/2;

//left child (i) = 2 * i;

//right child(i) = 2 * i + 1;


//从0开始
//parent(i) = (i-1)/2;

//left child (i) = 2 * i + 1;
//right child(i) = 2 * i + 2;

//从最后一个不是叶子的节点开始 从1
//count/2

//从最后一个不是叶子的节点开始 从0
//(count-1)/2

////todo 未完...待续... 4-6

//最大堆的骨架
template<typename Item>
class MaxHeap{

private:
	Item* data;
	int count;
	int capacity;
	
	void shiftUp(int k){
		
		//这个节点的父节点是否比当前值小
		while(k >1 && data[k/2] < data[k]){
		    swap(data[k/2],data[k]);
			k /= 2;//更新一下索引K
		}	
	}
	void shiftDown(int k){
		//在完全二叉树有有右孩子,一定有孩子
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
	}
	
public:
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
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
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	void insert(Item item){
		
		assert(count+1 <= capacity);
		
		data[count+1] = item;
		count ++;
		shiftUp( count );
	}
	
	Item extractMax(){
		
		assert(count > 0);
		
		Item ret = data[1];
		
		swap(data[1] , data[count]);
		count --;
		shiftDown(1);
		
		return ret;
		
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
