
#include <iostream>

using namespace std;

template <typename T>
class MyVector{

private:
	T* data;
    int capacity; //存储数组中可以容纳的最大的元素个数
	int size;     //存储数组中的元素个数
	
	//0(n)
	void resize( int newCapacity ){
		//新的容量可以容纳现有的容量
		assert( newCapacity >= size );
		
		//开辟一个新的数组
		T *newData = new T[newCapacity];
		//将原数组赋值到新数组
		for(int i = 0; i < size ; i++){
			newData[i] = data[i];
		}
		//释放掉原来的
		delete[] data;
		
		//改变指针
		data = newData;
		
		capacity = newCapacity;
	}
	
public:

	MyVector(){
		data = new T[10];
		
		capacity = 10;
		
		size = 0;
	}
	
		
	//析构函数要释放
	~MyVector(){
		delete[] data;
	}
	
	//添加一个元素
	//Average: 0(1)
	void push_back(T e){
		
		//assert( size < capacity );
		if(size == capacity){
			//重行分配空间
			resize( 2*capacity );
		}		
		
		data[size++] = e;		
	}
	
	//拿出数组最后一个元素
	T pop_back(){
		
		assert( size > 0 );
		
		//return data[--size];	
		size --;
		return data[size];
	}
	
};