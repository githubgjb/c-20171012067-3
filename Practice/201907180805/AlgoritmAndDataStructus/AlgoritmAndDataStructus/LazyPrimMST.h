
#include <vector>
#include "MinHeap.h"
#include "Edge.h"

using namespace std;

template<typename Graph,typename Weight>
class lazyPrimMST{
private:
	Graph &G;
	MinHeap<Edge<Weight>> pq;
	bool *marked;
	vector<Edge<Weight>> mst;
	Weight mstWeight;

	void visit(int v){
		assert(!marked[v]);
		marked[v] = true;

		typename Graph::adjIterator adj(G,v);
		for (Edge i = 0; i < length; i++)
		{

		}
	}

public:
	lazyPrimMST(Graph &graph):G(graph),pq(MinHeap<Edge<Weight>>(graph.E())){
		
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); i++)
		{
			marked[i] = false;
		}
		mst.clear();

		//Lazy Prim
		visit(0); 

	}
	~lazyPrimMST(){
		delete[] marked;
	}

	vector<Edge<Weight>> mstEdges(){
		return mst;
	}

	Weight result(){
		return mstWeight;
	}
};
