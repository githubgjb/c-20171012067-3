
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

//∂¡»°Õº
template <typename Graph>

class ReadGraph05{
private:
public:
	ReadGraph05(Graph &graph, const string &fileName){
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
			ss >> a >> b;
			assert(a >= 0 && a < V);
			assert(a >= 0 && a < V);
			graph.addEdge(a,b);

		}
		

	}
	~ReadGraph05(){}

};