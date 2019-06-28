

#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;

// ʹ��BellmanFord�㷨�����·��
template <typename Graph, typename Weight>
class BellmanFord13{

private:
	Graph &G;                   // ͼ������
	int s;                      // ��ʼ��
	Weight* distTo;             // distTo[i]�洢����ʼ��s��i�����·������
	vector<Edge<Weight>*> from; // from[i]��¼���·����, ����i��ı�����һ��
	bool hasNegativeCycle;      // ���ͼ���Ƿ��и�Ȩ��



public:
	// ���캯��, ʹ��BellmanFord�㷨�����·��
	BellmanFord13(Graph &graph, int s) :G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		// ��ʼ�����еĽڵ�s�����ɴ�, ��from��������ʾ
		for (int i = 0; i < G.V(); i++){
			from.push_back(NULL);
		}
		//Bellman-Ford

	}

	~BellmanFord13(){
		delete[] distTo;
		delete from[s];
	}

	// ����ͼ���Ƿ��и�Ȩ��
	bool negativeCycle(){
		return hasNegativeCycle;
	}

	// ���ش�s�㵽w������·������
	Weight shortestPathTo(int w){
		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);
		assert(hasPathTo(w));
		return distTo[w];
	}

	// �жϴ�s�㵽w���Ƿ���ͨ
	bool hasPathTo(int w){
		assert(w >= 0 && w < G.V());
		return from[w] != NULL;
	}

	// Ѱ�Ҵ�s��w�����·��, ������·�������ıߴ����vec��
	void shortestPath(int w, vector<Edge<Weight>> &vec){

		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);
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
		assert(!hasNegativeCycle);
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