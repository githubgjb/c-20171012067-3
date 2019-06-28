

#include <stack>
#include <vector>
#include "Edge.h"

using namespace std;

// 使用BellmanFord算法求最短路径
template <typename Graph, typename Weight>
class BellmanFord13{

private:
	Graph &G;                   // 图的引用
	int s;                      // 起始点
	Weight* distTo;             // distTo[i]存储从起始点s到i的最短路径长度
	vector<Edge<Weight>*> from; // from[i]记录最短路径中, 到达i点的边是哪一条
	bool hasNegativeCycle;      // 标记图中是否有负权环



public:
	// 构造函数, 使用BellmanFord算法求最短路径
	BellmanFord13(Graph &graph, int s) :G(graph){
		this->s = s;
		distTo = new Weight[G.V()];
		// 初始化所有的节点s都不可达, 由from数组来表示
		for (int i = 0; i < G.V(); i++){
			from.push_back(NULL);
		}
		//Bellman-Ford

	}

	~BellmanFord13(){
		delete[] distTo;
		delete from[s];
	}

	// 返回图中是否有负权环
	bool negativeCycle(){
		return hasNegativeCycle;
	}

	// 返回从s点到w点的最短路径长度
	Weight shortestPathTo(int w){
		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);
		assert(hasPathTo(w));
		return distTo[w];
	}

	// 判断从s点到w点是否联通
	bool hasPathTo(int w){
		assert(w >= 0 && w < G.V());
		return from[w] != NULL;
	}

	// 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
	void shortestPath(int w, vector<Edge<Weight>> &vec){

		assert(w >= 0 && w < G.V());
		assert(!hasNegativeCycle);
		assert(hasPathTo(w));

		// 通过from数组逆向查找到从s到w的路径, 存放到栈中
		stack<Edge<Weight>*> s;
		Edge<Weight> *e = from[w];
		while (e->v() != this->s){
			s.push(e);
			e = from[e->v()];
		}
		s.push(e);

		// 从栈中依次取出元素, 获得顺序的从s到w的路径
		while (!s.empty()){
			e = s.top();
			vec.push_back(*e);
			s.pop();
		}
	}

	// 打印出从s点到w点的路径
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