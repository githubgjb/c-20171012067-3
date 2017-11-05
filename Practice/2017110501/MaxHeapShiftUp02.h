

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
		
		assert(count + 1 <= capacity);
		
		data[count+1] =  item;
		count++;
		shiftUp( count );
		
	}
	
};

int main(){
	
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;
	
	return 0;
}

