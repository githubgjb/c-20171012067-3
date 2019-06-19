#ifndef INC_06_PATH_COMPRESSION_UNIONFIND1_H_UnionFind02
#define INC_06_PATH_COMPRESSION_UNIONFIND1_H_UnionFind02


#include <iostream>
#include <cassert>

using namespace std;

namespace UF2{
	class UnionFind02
	{
	private:
		int* parent;
		int count;

	public:
		UnionFind02(int count){
			parent = new int[count];
			this->count = count;		
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
			}
		}
		~UnionFind02(){
			delete[] parent;
		}
		int find(int p){
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				p = parent[p];
			}
			return p;
		}

		bool isConnected(int p,int q){
			return find(p) == find(q);
		}

		void unionElements(int p,int q){
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
			{
				return;
			}
			parent[pRoot] = qRoot;
		}

	};
}

#endif //INC_06_PATH_COMPRESSION_UNIONFIND1_H

