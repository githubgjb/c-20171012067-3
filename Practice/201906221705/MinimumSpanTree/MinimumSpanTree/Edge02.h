
#ifndef INC_06_KRUSKAL_ALGORITHM_EDGE02_H
#define INC_06_KRUSKAL_ALGORITHM_EDGE02_H

#include <iostream>
#include <cassert>

using namespace std;

// ��
template<typename Weight>
class Edge02{
private:
	int a, b;    // �ߵ������˵�
	Weight weight;  // �ߵ�Ȩֵ

public:
	// ���캯��
	Edge02(int a, int b, Weight weight){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	// �յĹ��캯��, ���еĳ�Ա������ȡĬ��ֵ
	Edge02(){}

	~Edge02(){}

	int v(){ return a; } // ���ص�һ������
	int w(){ return b; } // ���صڶ�������
	Weight wt(){ return weight; }    // ����Ȩֵ

	// ����һ������, ������һ������
	int other(int x){
		assert(x == a || x == b);
		return x == a ? b : a;
	}

	// ����ߵ���Ϣ
	friend ostream& operator<<(ostream &os, const Edge &e){
		os << e.a << "-" << e.b << ": " << e.weight;
		return os;
	}

	// �ߵĴ�С�Ƚ�, �ǶԱߵ�Ȩֵ�Ĵ�С�Ƚ�
	bool operator<(Edge<Weight>& e){
		return weight < e.wt();
	}
	bool operator<=(Edge<Weight>& e){
		return weight <= e.wt();
	}
	bool operator>(Edge<Weight>& e){
		return weight > e.wt();
	}
	bool operator>=(Edge<Weight>& e){
		return weight >= e.wt();
	}
	bool operator==(Edge<Weight>& e){
		return weight == e.wt();
	}
};

#endif //INC_06_KRUSKAL_ALGORITHM_EDGE02_H