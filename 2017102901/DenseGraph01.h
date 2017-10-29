
//稠密图 -- 邻接矩阵
class DenseGraph{
	
private:
    int n,m; //点数和边数
	bool directed; //有向图无向图
	vector<vector<bool>> g; //二维数组
	
public:
	DenseGraph(int n,bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for(int i=0 ; i<n ; i++){
			g.push_back(vector<bool>(n,false));
		}
	}
	
	~DenseGraph(){
				
	}
	
	int V(){return n;} //点
	int E(){return m;} //边
	
	void addEdge(int v,int w){//两个顶点索引,几行,几列
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		if(hasEdge( v , w )){
			return;
		}
		
		g[v][w] = true;
		if(!directed){ //如果是无向图
			g[w][v] = true;
		}
		m++;//增加一条边
	}
	
	//是否存在边
	bool hasEdge(int v,int w){
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		return g[v][w];
	}
	
};