//Binary Heap

//索引 , 值

//left,二倍,right 二倍加一

//索引
//值

//0  1  2  3  4  5  6  7  8  9 10 
//  62 41 30 28 16 22 13 19 17 15 

//parent(i) = i/2;

//left child (i) = 2 * i;

//right child(i) = 2 * i + 1;

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
	
public:
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
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
};

int main() {
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;
	
	srand(time(NULL));
	for(int i=0 ; i<15 ; i++){		
		maxheap.insert(rand()%100);	
	}
	
	return 0;
}
