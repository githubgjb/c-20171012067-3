
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SparseGraph05{
private:
	int n, m;
	bool directed;
	vector<vector<int>> g;
public:
	SparseGraph05(int n,bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<int>());
		}
	
	}
	~SparseGraph05(){}
	int V(){ return n; }
	int E(){ return m; }


	void addEdge(int v,int w){
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		g[v].push_back(w);
		if (v != w && !directed)
		{
			g[w].push_back(v);
		}


	}
	bool hasEdge(int v, int w){
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		for (int i = 0; i < g[v].size(); i++)
		{
			if (g[v][i] == w)
			{
				return true;
			}
		}

		return false;
	}
};