#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include <time.h>

#include "ReadGraph.h"

using namespace std;

int main(){
	string filename = "testG1.txt";

	SparseGraph g1(13,false);

	ReadGraph<SparseGraph> readGraph1(g1,filename);

	g1.show();

	cout << endl;

	DenseGraph g2(13,false);
	ReadGraph<DenseGraph> reandGraph2(g2,filename);

	g2.show();

	return 0;
}