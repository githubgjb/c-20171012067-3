#include <iostream>
#include <cassert>

using namespace std;

template<typename Weight>
class Edge{
private:
	int a, b;
	Weight weight;

public:
	Edge(int a, int b, Weight weight){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	Edge(){}

	~Edge(){}

	int v(){
		return a;//��1
	}

	int w(){
		return b;//��2
	}

	Weight wt(){
		return weight;//Ȩֵ
	}

	//����һ�����㷵����һ������
	int other(int x){
		assert(x == a || x == b);
		return x == a ? b : a;
	}

	//����<<
	friend ostream& operator<<(ostream &os,const Edge &e){
		os << e.a << "-" << e.b << ":" << e.weight;
		return os;
	}

	//����<
	bool operator<(Edge<Weight>& e){
		return weight < e.wt;
	}

	bool operator<=(Edge<Weight>& e){
		return weight <= e.wt;
	}

	bool operator>(Edge<Weight>& e){
		return weight > e.wt;
	}

	bool operator>=(Edge<Weight>& e){
		return weight >= e.wt;
	}

	bool operator==(Edge<Weight>& e){
		return weight == e.wt;
	}
};
