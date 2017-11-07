

namespace UF4{
	class UnionFind{
	private:
	
		int* parent;
		int* rank;    //rank[i]表示以i为根的集合所表示的树的层数
		int count;
	
	public:
	    UnionFind(int count){
			parent = new int[count];
			rank = new int[count];
			this->count = count;
			for(int i=0;i<count;i++){
				parent[i] = i;
				rank[i] = 1;
			}
		}
		
		~UnionFind(){
			delete[] parent;
			delete[] rank;
		}
		int find(int p){
			assert( p >=0 && p < count );
			//只要自己不等于父亲就没到根
			while( p != parent[p] ){
				parent[p] = parent[parent[p]];//等于他父亲的父亲
				
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
			
			if(rank[pRoot] < rank[qRoot]){
				parent[pRoot] = qRoot; //更改根的值
				
			}else if(rank[qRoot] < rank[pRoot]){
				
				parent[qRoot] = pRoot;
			}else{//rank[pRoot] == rank[qRoot]
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}					
		}
			
	};	
}