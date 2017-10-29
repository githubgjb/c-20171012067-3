
//稀疏图 -- 邻接表
class SparseGraph{
	
private:
    int n,m; //点数和边数
	bool directed; //有向图无向图
	vector<vector<int>> g; //二维数组
	
public:
	SparseGraph(int n,bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for(int i=0 ;i<n i++){
			g.push_back( vector<int> );//放一个空的vector
		}		
	}
	
	~SparseGraph(){
		
	}
	int V(){return n;} //点
	int E(){return m;} //边
	
	void addEdge( int v,int w ){
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		g[v].push_back(w);
		if( v != w && !directed ){
			g[w].push_back(v);
		}
		
		m ++;
	}
	
	bool hasEdge(int v,int w){
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		for(int i=0 ; i<g[v].size() ; i++){
			if(g[v][i] == w){
				return true;
			}
		}
		return false;
	}
	
};