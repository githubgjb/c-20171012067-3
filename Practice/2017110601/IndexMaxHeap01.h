

template<typename Item>
class MaxHeap{
	
private: 
	Item* data;
	
	int* indexes; //引用,索引数组
	
	int count;
	int capacity;
	
	void shiftUp(int k){
		
		//判断的是data里的值
		while(k > 1 && data[indexes[k/2]] < data[indexes[k]] ){//父节点是不是比子节点小
			//交换的是索引
			swap(indexes[k/2],indexes[k]);
			//k = k/2;  //更新一下k
            k /= 2;			
		}
	}
	
	void shiftDown(int k){
		
		while( 2*k <= count ){ //完全二叉树中,有左孩子就一定有孩子
			
			int j = 2*k; //在此轮循环中,data[k]和data[j]交换位置
			
			//再判断有没有右孩子  //右孩子比左孩子大
			if(j+1 <= count  &&  data[indexes[j+1]] > data[indexes[j]]){
				j += 1;				
			}
			
			//当前元素比左孩子或右孩子都大
			if(data[indexes[k]] >= data[indexes[j]]){
				break; //可以结束循环了				
			}
			
			swap(indexes[k],indexes[j]);
			k = j;
		}		
	}
	
public:
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexes = new int[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}

	~MaxHeap(){
		delete [] data;	
		delete [] indexes;
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	//插入元素时,要指定索引
	//传入的i对用户而言,是从索引0开始的
	void insert(int i, Item item){
		
		assert(count + 1 <= capacity);
		assert(i+1 >= 1 && i + 1 <= capacity);
		
		i += 1;
        
		//在指定的元素中插入
		data[i] =  item;
		indexes[count+1] = i; //增加索引
		
		
		count++;
		shiftUp( count );
		
	}
	
	Item extractMax(){
		
		assert( count > 0 );
		
		Item ret = data[indexes[1]];
		
		//交换的是索引了不是值了
		swap( indexes[1], indexes[count] );
		count --;
		
		shiftDown(1);
		
		return ret;
	}
	
	//返回最大元素的索引
	int extractMaxIndexes(){
		
		assert( count > 0 );
		
		//外部的用户的引索是从0开始的,所以减一
		int ret = indexes[1] - 1;
		
		//交换的是索引了不是值了
		swap( indexes[1], indexes[count] );
		count --;
		
		shiftDown(1);
		
		return ret;
	}
	
	//通过给定索引值i,来找到指定的data
	Item getItem(int i) {
		       //用户的索引值从0开始
			   //内部的索引值从1开始
		return data[i+1];
	}
	
	//外部用户修改指定的元素的值
	void change(int i,Item newItem){
		
		i += 1;
		data[i] = newItem;
		
		//但是要维护索引堆呀!
		//根据值,找到索引
		
		//找到indexes[j] = i,j表示data[i]在堆中的位置
		//之后shiftUp(j),再shiftDown(j)
		
		
		//维护索引堆
		for(int j = 1 ; j <= count ; j++){
			if( indexes[j] == i ){
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
			
	}	
};

int main(){
	
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;
	
	return 0;
}

