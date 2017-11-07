

namespace UF2{
	class UnionFind{
	private:
	
		int* parent;
		int count;
	
	public:
	    UnionFind(int count){
			parent = new int[count];
			this->count = count;
			for(int i=0;i<count;i++){
				parent[i] = i;
			}
		}
		
		~UnionFind(){
			delete[] parent;
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
			
			parent[pRoot] = qRoot; //更改根的值
			
		}
			
	};	
}