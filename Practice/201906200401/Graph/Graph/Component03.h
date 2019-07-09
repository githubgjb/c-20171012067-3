#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component03{
private:
	Graph &G;
	bool *visited;
	int ccount;
	int *id;

	void dfs(int v){
		visited[v] = true;
		id[v] = ccount;
		typename Graph::adjIterator adj(G,v);
		for (int i = adj.begin(); !adj.end(); adj.next())
		{
			if (!visited[i])
			{
				dfs(i);
			}

		}

	}

public:
	Component03(Graph &graph):G(graph){
		visited = new bool[G.V()];
		id = new int[G.V()];
		ccount = 0;
		for (int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			id[i] = -1;
		}

		for (int i = 0; i < G.V(); i++)
		{
			if (!visited[i])
			{
				dfs(i);
				ccount++;
			}

		}
	
	}

	~Component03(){
		delete[] visited;
		delete[] id;
	}
	
	int count(){
		return ccount;
	}

	bool isConnected(int v,int w){
		assert(v >= 0 && v < G.V());
		assert(w >= 0 && w < G.V());

		return id[v] == id[w];
	}
};