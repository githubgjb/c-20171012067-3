#ifndef INC_06_PATH_COMPRESSION_UNIONFIND1_H_UnionFind03
#define INC_06_PATH_COMPRESSION_UNIONFIND1_H_UnionFind03


#include <iostream>
#include <cassert>

using namespace std;

namespace UF3{
	class UnionFind03
	{
	private:
		int* parent;
		//int* sz; //sz[i]表示以i为根的集合中元素个数
		int* rank; //rank[i]表示以i为根的集合所表示的树的层数
		int count;

	public:
		UnionFind03(int count){
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
		~UnionFind03(){
			delete[] parent;
			//delete[] sz;
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

