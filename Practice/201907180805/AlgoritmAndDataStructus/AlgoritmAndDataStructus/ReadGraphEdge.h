
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template<typename Graph,typename Weight>
class ReadGraphEdge{
private:
public:
	ReadGraphEdge(Graph &graph, const string &fileName){

		ifstream file(fileName);
		string line;
		int V, E;

		assert(file.is_open());

		assert(getline(file, line));
		stringstream ss(line);
		ss >> V >> E;

		assert(V == graph.V());

		for (int i = 0; i < E; i++)
		{
			assert(getline(file, line));
			stringstream ss(line);
			int a, b;
			Weight w;
			ss >> a >> b >> w;
			assert(a >= 0 && a <= V);
			assert(b >= 0 && b <= V);
			graph.addEdge(a, b, w);
		}

	}
	~ReadGraphEdge(){}
};

