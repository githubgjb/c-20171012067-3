
#include <iostream>
#include <cassert>
using namespace std;

namespace UF4{
	class UnionFind04{
	private:
		int *parent;
		int* rank; //rank[i]表示以i为根的集合所表示的树的层数
		int count;

	public:
		UnionFind04(int n){
			count = n;
			parent = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; i++)
			{
				parent[i] = i;
				rank[i] = 1;
			}
		}
		~UnionFind04(){
			delete[] parent;
			delete[] rank;
		}

		int find(int p){
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				p = parent[p];
			}
			return p;
		}

		bool isConnected(int p, int q){
			return find(p) == find(q);
		}

		void unionElements(int p, int q){
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
			else if( rank[qRoot] < rank[pRoot] ){
				parent[qRoot] = pRoot;
			}
			else{ //rank[pRoot] == rank[qRoot]
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
		}

	};
}

