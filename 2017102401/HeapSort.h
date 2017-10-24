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
	
public:
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
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
};

int main() {
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;
	
	return 0;
}
