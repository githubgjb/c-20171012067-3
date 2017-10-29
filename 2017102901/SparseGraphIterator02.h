
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
	
	class adjIterator{
	private:
		SparseGraph &G; //存储图的引用
		int v;          //存储那一个点
		int Index;      //迭代到那里了
		
	public:
	    //构造列表初始化,因为是引用
		adjIterator(SparseGraph &graph, int v):G(graph){//那一个图,那一个点
			this->v = v;
			this->index = 0;
		}
		
		//这个点所在的第一个边
		int begin(){
			index = 0;
			if(G.g[v].size()){
				return G.g[v][0];
			}
			return -1;
		}
		//访问这个节点的下一个边
		int next(){
			index ++;
			if( index < G.g[v].size() ){
				return G.g[v][index];
			}
			return -1;
			
		}
		//没有边了
		bool end(){
			return index >= G.g[v].size();
		}
	};
};