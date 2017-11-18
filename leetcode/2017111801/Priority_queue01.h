#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

bool myCmp(int a,int b){
	
	//比较a和b的个位数,谁小谁排前面
	return a%10 < b%10;
}

int main(){	
	srand( time(NULL) );
	
	//默认请况下是最大堆
	priority_queue<int> pq;

	for(int i=0; i<10 ;i++){
		
		int num = rand()%100; //0-99
		//放入到优先队列中
		pq.push( num );
		
		cout<<"insert " <<num<<" in priority queue. "<<endl;
		
	}
	
	//把优先队列中的数取出来
	while( !pq.empty()){		
		cout<<pq.top()<<" ";
		pq.pop();
	}
	
	//打印两个回车
	cout<<endl<<endl;
	
	//下面是最小堆greater比较函数
	priority_queue<int,vector<int>,greater<int> > pq2;
	
	for(int i=0; i<10 ;i++){
		
		int num = rand()%100; //0-99
		//放入到优先队列中
		pq2.push( num );
		
		cout<<"insert " <<num<<" in priority queue. "<<endl;
		
	}
	
	//把优先队列中的数取出来
	while( !pq2.empty()){		
		cout<<pq2.top()<<" ";
		pq2.pop();
	}
	
	//打印两个回车
	cout<<endl<<endl;
	
	//自定义比较关系 传入一个比较函数
	priority_queue<int,vector<int>,function<bool(int,int)>> pq3(myCmp);
	
	
	for(int i=0; i<10 ;i++){
		
		int num = rand()%100; //0-99
		//放入到优先队列中
		pq3.push( num );
		
		cout<<"insert " <<num<<" in priority queue. "<<endl;
		
	}
	
	//把优先队列中的数取出来
	while( !pq3.empty()){		
		cout<<pq3.top()<<" ";
		pq3.pop();
	}
	
	//打印两个回车
	cout<<endl<<endl;
	
	return 0;	
}