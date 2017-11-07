

namespace UF3{
	class UnionFind{
	private:
	
		int* parent;
		int* sz;    //sz[i]表示以i为根的集合中元素个数
		int count;
	
	public:
	    UnionFind(int count){
			parent = new int[count];
			sz = new int[count];
			this->count = count;
			for(int i=0;i<count;i++){
				parent[i] = i;
				sz[i] = 1;
			}
		}
		
		~UnionFind(){
			delete[] parent;
			delete[] sz;
		}
		int find(int p){
			assert( p >=0 && p < count );
			//只要自己不等于父亲就没到根
			while( p != parent[p] ){
				p = parent[p];//一直向上
			}
			return p;	
		}
		
		//根是不是一样
		bool isConnected( int p,int q ){
			return find(p) == find(q);
		}
		
		void unionElements(int p,int q){
			int pRoot = find(p);
			int qRoot = find(q);
			
			//根相等,说明已经连接在一起了
			if(pRoot == qRoot){
				return;
			}
			
			if(sz[pRoot] < sz[qRoot]){
				parent[pRoot] = qRoot; //更改根的值
				
				sz[qRoot] += sz[pRoot];
			}else{
				
				parent[qRoot] = pRoot;
				
				sz[pRoot] += sz[qRoot];
			}					
		}
			
	};	
}