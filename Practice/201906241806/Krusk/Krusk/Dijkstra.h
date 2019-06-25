#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class Dijkstra{

private:
	Graph &G;
	int s;

	Weight *distTo;
	bool *marked;
	vector<Edge<Weight*>> from;

public:
	Dijkstra(Graph &graph,int s):G(graph){

		this->s = s;
		distTo = new Weight[G.V()];
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); i++)
		{
			distTo[i] = Weight();
			marked[i] = false;
			from.push_back(NULL);
		}
		IndexMinHeap<Weight> ipq(G.V());

		//Dijkstra



	}

	~Dijkstra(){
		delete[] distTo;
		delete[] marked;
	}

	Weight shortestPathTo( int w ){
		return distTo[w];
	}

	bool hasPathTo( int w ){
		return marked[w];
	}

	void shortestPath(){
	
	
	}

};