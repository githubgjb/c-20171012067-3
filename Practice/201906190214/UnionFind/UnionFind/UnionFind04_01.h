

#include <iostream>
#include <cassert>

using namespace std;

namespace UF401{
	class UnionFind04_01
	{
	private:
		int *parent;
		int *rank;
		int count;


	public:
		UnionFind04_01(int count){
			parent = new int[count];
			rank = new int[count];
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
				rank[i] = 1;
			}
		
		}
		~UnionFind04_01(){
			delete[] parent;
			delete[] rank;
		}

		int find(int p){
			assert(p >= 0 && p < count);
			if (p != parent[p])
			{
				parent[p] = find(parent[p]);
			}
			return parent[p];
		}

		bool isConnected(int p ,int q){
			return find(p) == find(q);
		}

		void unionElements(int p,int q){
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
			{
				return;
			}

			if (rank[pRoot] < rank[qRoot])
			{
				parent[pRoot] = qRoot;
			}
			else if (rank[qRoot] < rank[pRoot])
			{
				parent[qRoot] = pRoot;
			}
			else{
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}

		}
	};
}
