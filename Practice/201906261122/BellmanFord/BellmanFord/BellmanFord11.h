

#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;

// ʹ��BellmanFord�㷨�����·��
template <typename Graph, typename Weight>
class BellmanFord11{

private:
	Graph &G;                   // ͼ������
	int s;                      // ��ʼ��
	Weight* distTo;             // distTo[i]�洢����ʼ��s��i�����·������
	vector<Edge<Weight>*> from; // from[i]��¼���·����, ����i��ı�����һ��
	bool hasNegativeCycle;      // ���ͼ���Ƿ��и�Ȩ��

	bool detectNegativeCycle(){
	
		for (int i = 0; i < G.V(); i++)
		{
			typename Graph::adjIterator adj(G, i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
			{
				if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()])
				{
					return true;
				}
			}
		}
		return false;
	}

public:
	// ���캯��, ʹ��BellmanFord�㷨�����·��
	BellmanFord11(Graph &graph, int s) :G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		// ��ʼ�����еĽڵ�s�����ɴ�, ��from��������ʾ
		for (int i = 0; i < G.V(); i++){
			from.push_back(NULL);
		}
		//Bellman-Ford
		distTo[s] = Weight();

		//v - 1 Relaxation
		for (int pass = 1; pass < G.V(); pass++)
		{
			for (int i = 0; i < G.V(); i++)
			{
				typename Graph::adjIterator adj(G,i);
				for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
				{
					if ( !from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()] )
					{
						distTo[e->w()] = distTo[e->v()] + e->wt();
					}
				}
			}
		}
		hasNegativeCycle = detectNegativeCycle();
	}

	~BellmanFord11(){
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