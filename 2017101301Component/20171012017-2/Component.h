#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component{

private:
	Graph &G;//图
	bool *visited; //是否被访问过
	int ccount; //记录有多少个联通分量

	int *id; //并查集

	void dfs(int v){

		visited[v] = true;
		id[v] = ccount;


		//迭代器获得邻边的方式
		typename Graph::adjIterator adj(G,v);
		for (int i = adj.begin(); !adj.end();i=adj.next())
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

	}

public:

	Component(Graph &graph)：G(Graph){
		visited = new bool[G.V()];//这张图有多少个节点
		id = new int[G.V()];
		
		ccount = 0;
		//初始化,每一个元素都没被访问过
		for (int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			id[i] = -1;

		}

		
		for (int i = 0; i < G.V(); i++)
		{
			if (!visited[i]){
				//进行深度优先遍历
				dfs(i);
				//增加联通分量
				ccount++;
			}
		}

	}

	~Component(){
		delete[] visited;
		delete[] id;
	}

	int count(){
		return ccount;
	}

	bool isConnected(int v,int w){
		assert(v >= 0 && v < G.V() );
		assert(w >= 0 && w < G.V());
		return id[v] == id[w];
	}
};

