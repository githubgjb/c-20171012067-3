
//最小堆
template<typename Item>
class MinHeap{

private:
   Item *data;
   int count;
   int capacity;
   
   
   //插入
   void shiftUp(int k){
	   //父节点比左孩子大
       while(k > 1 && data[k/2] > data[k]){
		   swap(data[k/2],data[k]);
	   }   
   }
   
   //删除
   void shiftDown(int k){
	   while(2*k <= count){
		   int j = 2 * k; //左孩子
		   //有右孩子          //右孩子小于左孩子
		   if( j+1 <= count && data[j+1] < data[j]){
			   j++ ; //什么也不用做,继续向下
		   }
		   //已经找到合适的位置了
		   if(data[k] <= data[j] ){
			   break;
		   }
		   swap(data[k],data[j]);
		   k = j;
	   }
   }

public: 
  
  
    //todo 8-3 09:17
	MinHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	
	~MinHeap(){
		delete[] data;
	}
	
}