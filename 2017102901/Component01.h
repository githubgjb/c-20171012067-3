
template<typename Graph>
class Component{

private:
	Graph &G;
	bool *visited;
	int ccount;		//联通分量
	int *id; //用于检查是否相连接
	
	
	//深度优先遍历
	void dfs(int v){		
		visited[v] = true;
		id[v] = ccount;
		//迭代这个点
		typename Graph:adjIterator adj(G,v);
		for(int i=adj.begin() ; !adj.end() ; i = adj.next()){
			if( !visited[i]){
				dfs(i);//递归
			}
		}		
	}
public:
	Component(Graph &graph):G(graph){
		//一张图有多少个节点就开多少个空间
		visited = new bool[G.V()];
		id = new int[G.V()];//图中顶点的个数
		ccount = 0;
		
		//初始化数组
		for(int i=0 ; i<G.V() ;i++){
			visited[i] = false;
			id[i] = -1;
		}
		
		for(int i=0 ; i<G.V() ; i++){
			if( !visited[i] ){
				dfs(i);
				ccount ++;
			}
		}
	}
	
	~Component(){
		delete[] visited;
		delete[] id;
	}
	
	int count(){
		return ccount;
	}
	
	bool isConnected(int v,int w){
		assert( v>=0 && v < G.V() );
		assert( w>=0 && w < G.V() );
		return id[v] == id[w];
	}
};