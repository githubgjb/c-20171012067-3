#include <iostream>
#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

// Dijkstra�㷨�����·��
template<typename Graph, typename Weight>
class Dijkstra02{

private:
	Graph &G;                   // ͼ������
	int s;                      // ��ʼ��
	Weight *distTo;             // distTo[i]�洢����ʼ��s��i�����·������
	bool *marked;               // �������, ���㷨���й����б�ǽڵ�i�Ƿ񱻷���
	vector<Edge<Weight>*> from; // from[i]��¼���·����, ����i��ı�����һ��
	// ���������ָ��������·��

public:
	// ���캯��, ʹ��Dijkstra�㷨�����·��
	Dijkstra02(Graph &graph, int s) :G(graph){

		// �㷨��ʼ��
		assert(s >= 0 && s < G.V());
		this->s = s;
		distTo = new Weight[G.V()];
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); i++){
			distTo[i] = Weight();
			marked[i] = false;
			from.push_back(NULL);
		}

		// ʹ�������Ѽ�¼��ǰ�ҵ��ĵ���ÿ���������̾���
		IndexMinHeap<Weight> ipq(G.V());

		//Dijkstra

		
	}

	// ��������
	~Dijkstra02(){
		delete[] distTo;
		delete[] marked;
		delete from[0];
	}

	// ���ش�s�㵽w������·������
	Weight shortestPathTo(int w){
		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));
		return distTo[w];
	}

	// �жϴ�s�㵽w���Ƿ���ͨ
	bool hasPathTo(int w){
		assert(w >= 0 && w < G.V());
		return marked[w];
	}

	// Ѱ�Ҵ�s��w�����·��, ������·�������ıߴ����vec��
	void shortestPath(int w, vector<Edge<Weight>> &vec){

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		// ͨ��from����������ҵ���s��w��·��, ��ŵ�ջ��
		stack<Edge<Weight>*> s;
		Edge<Weight> *e = from[w];
		while (e->v() != this->s){
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);

		// ��ջ������ȡ��Ԫ��, ���˳��Ĵ�s��w��·��
		while (!s.empty()){
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}

	// ��ӡ����s�㵽w���·��
	void showPath(int w){

		assert(w >= 0 && w < G.V());
		assert(hasPathTo(w));

		vector<Edge<Weight>> vec;
		shortestPath(w, vec);
		for (int i = 0; i < vec.size(); i++){
			cout << vec[i].v() << " -> ";
			if (i == vec.size() - 1)
				cout << vec[i].w() << endl;
		}
	}
};