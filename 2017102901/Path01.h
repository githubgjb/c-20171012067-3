
template<typename Graph>
class Path{

private:
	Graph &G;
	int s;
	bool *visited;
	int * from;
	
	//深度优先遍历
	void dfs(int v){		
		visited[v] = true;
		
		//迭代这个点
		typename Graph:adjIterator adj(G,v);
		for(int i=adj.begin() ; !adj.end() ; i = adj.next()){
			if( !visited[i]){
				from[i] = v; //i结节是从v过来的
				dfs(i);//递归
			}
		}		
	}

public:
	Path(Graph &graph,int s):G(graph){
		
		//算法初始化
		assert( s>=0 && s<G.V );
		
		visited = new bool[G.V()];
		from = new int[G.V()];
		
		for(int i=0;i < G.V() ;i++){
			visited[i] = false;
			from[i] = -1;
		}
		this->s = s;
		
		//寻路算法
		dfs(s);
		
	}
	
	~Path(){		
		delete [] visited;
		delete [] from;		
	}
	
	bool hasPath(int w){
		assert(w >= 0 && w < G.V() );
		//s到w是否有路
		return visited[w];
	}
	
	void path(int w,vetor<int> &vec){
		
		stack<int> s; //栈,先进后出
		
		int p = w;
		
		while( p != -1){
			s.push(p);
			//倒推
			p = from[p];
		}
		
		vec.clear();
		while(!s.empty()){
			vec.push_back( s.top() );//栈顶//正序放入所有元素
			s.pop();
		}
		
	}
	
	void showPath(int w){
		vector<int> vec;
		path( w , vec );
		for(int i=0 ; i<vec.size() ; i++){
			cout<<vec[i];
			if(i == vec.size()-1){ //向量中最后一个元素
				cout<<endl;
			}else{
				cout<<" -> ";
			}
		}
	}

};