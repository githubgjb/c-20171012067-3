
#include <iostream>

using namespace std;


//模板类
template<typename Weight>
class Edge{
	
private:
	int a,b;
	Weight weight;

public:	

	Edge(int a,int b, Weight weight){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	
	Edge(){
		
	}
	
	~Edge(){
		
	}
	
	//两个顶点,和权值
	int v() {return a;}
	
	int w() {return b;}
	
	Weight wt() {return weight;}
	
	//根据一个顶点知道另一个顶点
	int other(int x){
		assert(x == a || x == b);
		return x == a ? b : a;
	}
	
	//重载
    friend ostream& operator<<(ostream &os, const Edge &e){
		os << e.a << "-" << e.b << ": " << e.weight;
		return os;
	}
	
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