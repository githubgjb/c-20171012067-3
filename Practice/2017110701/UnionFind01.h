
#include <iostream>
#include <cassert>

using namespace std;


class UnionFind{

private:
	int* id; //数组
	int count; //计数
	

public:
    //这个并查集有多少个元素
	UnionFind(int n){
		count = n;
		id = new int[n];
		
		//初始化的情况下,
		//每一个自己都是
		//独立的组
		for(int i=0 ; i<n ; i++ ){
			id[i] = i;
		}
		
	}
	
	~UnionFind(){
		delete [] id;
	}
	
	int find(int p){
		assert( p >= 0 && p < count );
		
		return id[p];
	}
	
	bool isConnected(int p,int q){
		return find(p) == find(q);
	}
	
	void unionElements(int p,int q){
		
		int pID = find(p);
		int qID = find(q);
		
		
		//如果已经是并上了
		if(pID == qID){
			return;
		}
		
		for(int i=0 ; i<count ; i++){
			if(id[i] == pID){
				id[i] = qID;
			}
		}
		
	}

};

int main(){
	
	return 0;
}