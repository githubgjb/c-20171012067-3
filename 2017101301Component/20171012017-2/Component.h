#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component{

private:
	Graph &G;//ͼ
	bool *visited; //�Ƿ񱻷��ʹ�
	int ccount; //��¼�ж��ٸ���ͨ����

	int *id; //���鼯

	void dfs(int v){

		visited[v] = true;
		id[v] = ccount;


		//����������ڱߵķ�ʽ
		typename Graph::adjIterator adj(G,v);
		for (int i = adj.begin(); !adj.end();i=adj.next())
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}

	}

public:

	Component(Graph &graph)��G(Graph){
		visited = new bool[G.V()];//����ͼ�ж��ٸ��ڵ�
		id = new int[G.V()];
		
		ccount = 0;
		//��ʼ��,ÿһ��Ԫ�ض�û�����ʹ�
		for (int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			id[i] = -1;

		}

		
		for (int i = 0; i < G.V(); i++)
		{
			if (!visited[i]){
				//����������ȱ���
				dfs(i);
				//������ͨ����
				ccount++;
			}
		}

	}

	~Component(){
		delete[] visited;
		delete[] id;
	}

	int count(){
		return ccount;
	}

	bool isConnected(int v,int w){
		assert(v >= 0 && v < G.V() );
		assert(w >= 0 && w < G.V());
		return id[v] == id[w];
	}
};

