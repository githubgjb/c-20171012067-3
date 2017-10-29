

template<typename Weight>
class Edge{
private:
    int a,b;
	Weight weight;

public:
    
    Edge(int a,inb b,Weight weight){
		this->a = a;
		this->b = b;
		this->weight = weight; 
	}
  
    Edge(){}
    	
	~Edge(){
		
	}
	int v(){return a;}
	int w(){return b;}
	
	Weight wt(){
		return weight;
	}
	
	//根据一个顶点知道另外一个顶点
	int other(int x){
		assert( x == a || x == b);
		return x == a ? b : a ;
	}
	
	//重载<<
	
	friend ostream& operator<<(ostream &os, const Edge &e){
		os<<e.a<<"-"<<e.b<<":"<<e.weight;
		return os;
	}
	
	//重载<	
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