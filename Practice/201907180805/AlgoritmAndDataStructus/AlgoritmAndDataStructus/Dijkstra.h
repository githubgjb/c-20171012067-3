
#include <iostream>
#include <vector>
#include <stack>
//#include "Edge.h"
//#include "IndexMinHeap.h"
//命名空间的问题,变量相互干扰，先回滚，让它好使

#include "GraphDijkistraEdge.h"
#include "GraphDijkistraIndexMinHeap.h"
#include "GraphDijkistraSparseGraph.h"
#include "GraphDijkistraDenseGraph.h"

using namespace std;

namespace GraphDijkistra{
	template<typename Graph, typename Weight>
	class Dijkstra{

	private:
		Graph &G;
		int s;
		

		Weight *distTo;
		bool *marked;
		//vector<Edge<Weight*>> from;
		vector<GraphDijkistra::Edge<Weight>*> from;

	public:
		Dijkstra(Graph &graph, int s) :G(graph){

			this->s = s;
			distTo = new Weight[G.V()];
			marked = new bool[G.V()];
			for (int i = 0; i < G.V(); i++)
			{
				distTo[i] = Weight();
				marked[i] = false;
				from.push_back(NULL);
			}
			GraphDijkistra::IndexMinHeap<Weight> ipq(G.V());

			//Dijkstra
			distTo[s] = Weight();
			marked[s] = true;
			ipq.insert(s, distTo[s]);

			while (!ipq.isEmpty())
			{
				int v = ipq.extractMinIndex();
				//distTo[v]就是s到v的最短路径
				marked[v] = true;

				//Relaxation
				
				typename GraphDijkistra::Graph::adjIterator adj(G, v);
				for (GraphDijkistra::Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
				{
					int w = e->other(v);
					if (!marked[w])
					{
						if (from[w] == NULL || distTo[v] + e->wt() < distTo[w])
						{
							distTo[w] = distTo[v] + e->wt();
							from[w] = e;
							if (ipq.contain(w))
							{
								ipq.change(w, distTo[w]);
							}
							else
							{
								ipq.insert(w, distTo[w]);
							}
						}
					}
				}

			}



		}

		~Dijkstra(){
			delete[] distTo;
			delete[] marked;
		}

		Weight shortestPathTo(int w){
			return distTo[w];
		}

		bool hasPathTo(int w){
			return marked[w];
		}

		void shortestPath(int w, vector<GraphDijkistra::Edge<Weight>> &vec){

			stack<GraphDijkistra::Edge<Weight> *> s;
			GraphDijkistra::Edge<Weight> *e = from[w];
			while (e->v() != e->w())
			{
				s.push(e);
				e = from[e->v()];
			}

			while (!s.empty())
			{
				e = s.top();
				vec.push_back(*e);
				s.pop();
			}

		}

		void showPath(int w){

			assert(w >= 0 && w < G.V());

			vector<GraphDijkistra::Edge<Weight>> vec;
			shortestPath(w, vec);
			for (int i = 0; i < vec.size(); i++)
			{
				cout << vec[i].v() << " -> ";
				if (i == vec.size() - 1)
				{
					cout << vec[i].w() << endl;
				}
			}

		}

	};
}
/*
template<typename Graph,typename Weight>
class Dijkstra{

private:
	Graph &G;
	int s;

	Weight *distTo;
	bool *marked;
	vector<Edge<Weight>*> from;

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
		distTo[s] = Weight();
		marked[s] = true;
		ipq.insert( s, distTo[s] );
		while (!ipq.isEmpty())
		{
			int v = ipq.extractMinIndex();
			//distTo[v] 就是s到v的最短距离
			marked[v] = true;

			//Relaxation
			typename Graph::adjIterator adj(G, v);
			for (Edge<Weight>* e = adj.begin(); !adj.next(); e = adj.next())
			{
				int w = e->other(v);
				if (!marked[w])
				{
					if (from[w] == NULL ||distTo[v]+ e->wt() < distTo[w])
					{
						distTo[w] = distTo[v] + e->wt();
						from[w] = e;

						if (ipq.contain(w))
						{
							ipq.change(w, distTo[w]);
						}
						else{
							ipq.insert(w, distTo[w]);
						}
					}
				}
			}

		}
	}
	~Dijkstra(){
		delete[] distTo;
		delete[] marked;
	}

	Weight shortestPathTo(int w){
		return distTo[w];
	}

	bool hasPathTo(int w){
		return marked[w];
	}
	
	void shortestPath(int w,vector<Edge<Weight>> &vec){
		stack<Edge<Weight>*> s;
		Edge<Weight> *e = from[w];
		while (e->v() != e->w())
		{
			s.push(e);
			e = from[e->v()];
		}

		while (!s.empty())
		{
			e = s.top();
			vec.push_back( *e );
			s.pop();
		}
	}
	
	void showPath(int w){
		assert(w >= 0 && w < G.V());

		vector<Edge<Weight>> vec;
		shortestPath(w, vec);
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i].v() << " -> ";
			if (i == vec.size()-1)
			{
				cout << vec[i].w() << endl;
			}
		}
	}
};
*/