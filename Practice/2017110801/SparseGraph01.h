

//稀疏图 - 邻接表
class SparseGraph{

private:
	int n , m;  //点和边
	bool directed; //有向还是无向图
	vector<vector<int>> g;
	

public:
    SparseGraph( int n,bool directed ){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		
		for(int i=0; i<n ; i++){
			//每一个g(i)都是一个空的向量
			g.push_back( vector<int>() );
		}
	}
	
	~SparseGraph(){
				
	}
	
	//返回点
	int V(){return n;} 
	//返回边
	int E(){return m;}

	//添加v 到 w的边
	void addEdge(int v,int w){
		
	    //首先要考虑v和w不越界
	    assert(v >= 0 && v < n);
	    assert(w >= 0 && w < n);
		
		g[v].push_back(w);
		//不管平行边,允许平行边,
		//判断平行边,成本太高
		
		
		//自环边,v和w是一致的话
		
		//是不是有向图,如果是无向图的话
		if( v != w && !directed ){
			g[w].push_back(v);			
		}
		
		m++;
		
	}
	
	bool hasEdge(int v , int w ){
		
		//首先要考虑v和w不越界
	    assert(v >= 0 && v < n);
	    assert(w >= 0 && w < n);
		
		for(int i=0; i< g[v].size() ;i++){
			if(g[v][i] == w){
				return true;
			}
		}
		return false;
	}
	
	
};