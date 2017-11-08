

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
	
	class adjIterator{
	
	private:		
		//对这个图和顶点进行存储
		SparseGraph &G;
		int v;
		int index; //索引,迭代到那里边了
		
	public:
        //迭代哪一个图,迭代哪一个顶点,G是一个引用,用构造列表来初始化
	    adjIterator(SparseGraph &graph, int v):G(graph){
			this->v = v;
			this->index = 0;
		}
		
		int begin(){ //开始
		    index = 0;
		    //v这个节点图中第一个元素
			if(G.g[v].size()){
				return G.g[v][index];  //index初始化为0
			}
			return -1;
		}
		
		int next(){  //下一个
			index ++;
			if(index < G.g[v].size()){
				return G.g[v][index];
			}
			return -1;
			
		}
		
		bool end(){  //结束没有
			return index >= G.g[v].size();
		}
	};
};