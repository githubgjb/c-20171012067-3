#ifndef INC_06_PATH_COMPRESSION_UNIONFIND1_H_UnionFind04
#define INC_06_PATH_COMPRESSION_UNIONFIND1_H_UnionFind04


#include <iostream>
#include <cassert>

using namespace std;

namespace UF4{
	class UnionFind04
	{
	private:
		int* parent;
		//int* sz; //sz[i]表示以i为根的集合中元素个数
		int* rank; //rank[i]表示以i为根的集合所表示的树的层数
		int count;

	public:
		UnionFind04(int count){
			parent = new int[count];
			//sz = new int[count];
			rank = new int[count];
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
				//sz[i] = 1;
				rank[i] = 1;
			}
		}
		~UnionFind04(){
			delete[] parent;
			//delete[] sz;
			delete[] rank;
		}
		int find(int p){
			assert(p >= 0 && p < count);
			/*
			while (p != parent[p])
			{
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			
			return p;
			*/
			if (p != parent[p])
			{
				parent[p] = find( parent[p] );
			}
			return parent[p];
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
			/*
			if (sz[pRoot] < sz[qRoot] )
			{
			parent[pRoot] = qRoot;
			sz[qRoot] += sz[pRoot];
			}
			else
			{
			parent[qRoot] = pRoot;
			sz[pRoot] += sz[qRoot];
			}
			*/

			//parent[pRoot] = qRoot;
			if (rank[pRoot] < rank[qRoot])
			{
				parent[pRoot] = qRoot;
			}
			else if (rank[qRoot] < rank[pRoot]){
				parent[qRoot] = pRoot;
			}
			else //rank[pRoot] == rank[qRoot]
			{
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}

		}

	};
}

#endif //INC_06_PATH_COMPRESSION_UNIONFIND1_H

