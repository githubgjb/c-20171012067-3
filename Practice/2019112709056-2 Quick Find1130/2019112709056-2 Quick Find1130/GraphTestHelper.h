#include <iostream>
#include <cassert>
#include <ctime>
#include "Graph1.h"
#include "ReadGraph01.h"
#include "Component01.h"
#include "Path01.h"

using namespace std;

namespace GraphTestHelper{
	void testGraph1(){
		int N = 20;
		int M = 100;
		srand(time(NULL));

		//Sparse Graph
		Graph1::SparseGraph g1(N , false);
		for (int i = 0; i < M; i++)
		{
			int a = rand() % N;
			int b = rand() % N;
			g1.addEdge( a , b );
		}
		
		for (int v = 0; v < N; v++)
		{
			cout << v << " : ";
			Graph1::SparseGraph::adjIterator adj(g1, v);
			for (int w = adj.begin(); !adj.end() ; w=adj.next())
			{
				cout << w << " ";
			}
			cout << endl;
		}

		//Dense Graph
		Graph1::DenseGraph g2(N, false);
		for (int i = 0; i < M; i++)
		{
			int a = rand() % N;
			int b = rand() % N;
			g2.addEdge(a, b);
		}

		for (int v = 0; v < N; v++)
		{
			cout << v << " : ";
			Graph1::DenseGraph::adjIterator adj(g2, v);
			for (int w = adj.begin(); !adj.end(); w = adj.next())
			{
				cout << w << " ";
			}
			cout << endl;
		}
	}
	
	void testReadGraph01(){
		string filename = "testG1.txt";
		Graph1::SparseGraph g1(13,false);
		ReadGraph01::ReadGraph<Graph1::SparseGraph> readGraph1(g1 , filename);
		Component01::Component<Graph1::SparseGraph> component1(g1);
		//g1.show();
		cout << "TestG1.txt,Component Count:" << component1.count() << endl;

		cout << endl;

		filename = "testG2.txt";
		Graph1::DenseGraph g2(7, false);
		ReadGraph01::ReadGraph<Graph1::DenseGraph> readGraph2(g2, filename);
		Component01::Component<Graph1::DenseGraph> component2(g2);
		//g2.show();
		cout << "TestG2.txt,Component Count:" << component2.count() << endl;

		cout << endl;

	}

	void testPath01(){
		string filename = "testG2.txt";
		Graph1::SparseGraph g(7, false);
		ReadGraph01::ReadGraph<Graph1::SparseGraph> readGraph1(g, filename);
		g.show();
		cout << endl;

		Path01::Path01<Graph1::SparseGraph> dfs(g , 0);
		cout << " DFS: ";
		dfs.showPath(6);

	}
}