
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph08{
private:
	int n, m;
	bool directed;
	vector<vector<bool>> g;

public:
	DenseGraph08(int n, bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<bool>(n, false));
		}
	}
	~DenseGraph08(){}
	int V(){ return n; }
	int E(){ return m; }

	void addEdge(int v, int w){
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w))
		{
			return;
		}
		g[v][w] = true;
		if (!directed)
		{
			g[w][v] = true;
		}
		m++;
	}

	bool hasEdge(int v, int w){
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}

	class adjIterator{
	private:
		DenseGraph08 &G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph08 &graph,int v):G(graph){
			this->v = v;
			this->index = -1;
		}
		~adjIterator(){}

		int begin(){
			index = -1;
			return next();
		}
		int next(){
			for (index += 1; index < G.V(); index++)
			{
				if (G.g[v][index])
				{
					return index;
				}
			}
			return -1;
		}
		bool end(){
			return index >= G.V();
		}

	};


};