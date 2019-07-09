
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

//∂¡»°Õº
template <typename Graph>

class ReadGraph04{
private:
public:
	ReadGraph04(Graph &graph, const string &fileName){
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
			assert(b >= 0 && b < V);
			graph.addEdge(a, b);
		}




	}
	~ReadGraph04(){}

};