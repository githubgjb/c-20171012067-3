
template<typename Graph>
class ShortestPath{
	
private:
	Graph &G;
	int s; //从那一个点开始
	bool  *visited;
	int *from;
	int *ord;//s到每一个节点最短距离

public:
	ShortestPath(Graph &graph,int s):G(graph){
		
		//算法初始化
		assert( s>=0 && s < graph.V() );
		
		visited = new bool[graph.V()];
		from = new int[graph.v()];
		ord = new int[graph.v()];
		
		for(int i=0 ; i< graph.V() ; i++){
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;
		
		queue<int> q;		
		
		//无向图最短路径算法
		
		//推入原点s
		q.push( s );
		visited[s] = true;
		ord[s] = 0; //原点距离自己为0
		while( !q.empty() ){
			//取出队首的元素
			int v = q.front();
			//移除出队
			q.pop();
			
			//遍历一下所有的相临的元素 g这个图中v这个节点
			typename Graph::adjIterator adj(G , v);
			
			//开始遍历
			for(int i=adj.begin() ; !adj.end(); i=adj.next() ){
				//有没有被访问过?
				if( !visited[i] ){
					q.push(i);//没被访问过,加入队列
					visited[i] = true; //访问过,就变为true
					from[i] = v; //从v这个节点访问过来的
					//从过来的节点加上1
					ord[i] = ord[v] + 1;
				}
			}
			
		}
		
	}
	
	~ShortestPath(){
		
		delete [] visited;
		delete [] from;
		delete [] ord;
		
	}
	
	//s到w有没有路径
	bool hasPath(int w){
		assert( w>=0 && w < G.V() );
		return visited[w];
	}
	
	
	//s到w的具体路径
	void path(int w,vector<int> &vec){
		assert( w>=0 && w < G.V() );
		
		stack<int> s;
		
		int p = w;
		while( p != -1){
			s.push(p);
			p = from[p];
		}
		
		vec.clear();
		while( !s.empty() ){
			vec.push_back( s.top() );
			s.pop();
		}
	}
	
	void showPath(int w){
		
		assert( w >= 0 && w<G.V() );
		vector<int> vec;
		path(w,vec);
		for(int i=0; i<vec.size() ; i++){
			cout<<vec[i];
			if(i == vec.size()-1){
				cout<<endl;
			}else{
				cout<<" -> ";
			}
		}
	}
	
	int length(int w){
		assert( w >= 0 && w<G.V() );
		return ord[w]; //返回长度
	}
	
	
};