
template <typename Graph>

class ShortestPath{

private:
    Graph &G;
	int s;
	bool *visited;
	int  *from;
	int  *ord; //s到每一个节点最短距离是多少


public:	
    
	ShortestPath(Graph &graph,int s):G(graph){
		//算法初始化
		assert( s>=0 && s < graph.V() );
		
		visited = new bool[graph.V()];
		from = new int[graph.V()];
		ord = new int[graph.V()];
		
		for(int i=0 ; i < graph.V() ; i++){
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		
		this->s = s;
		
		queue<int> q;
		
		//无向图最短路径算法
		//推入原点s
		q.push(s);
		visited[s] = true;
		ord[s] = 0; //原点距离自己是0
		
		while ( !q.empty()) {
			//取出来
			int v = q.front();
			//移除
			q.pop();
			
			//队列首元素所有相临的元素 ,G这个图中v这个节点
			typename Graph::adjIterator adj(G,v);
			
			for(int i = adj.begin() ; !adj.end() ; i = adj.next() ){
				//i这个节点有没有被访问过
				if( !visited[i] ){//没被访问过
					q.push(i);
					//维护相关信息
					visited[i] = true;
					//从v这个节点走到i的
					from[i] = v;
					//从他过来的节点的距离再加1
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
	
   bool hasPath(int w){
	   assert( w >= 0 && w < G.V() );
	   return visited[w];
   }
   
   void path(int w,vector<int> &vec){
	   //s -> w的路径 原点到w 
	   //根据from数组倒的推回去
	   
	   stack<int> s;
	   
	   int p = w;
	   while(p != -1){
		   s.push(p);
		   p = from[p];
	   }
	   
	   vec.clear();
	   //完成正序放入元素
	   while( !s.empty() ){
		   vec.push_back(s.top); //栈顶的元素
		   s.pop();	   
	   }
	   
   }
   
   void showPath(int w){
	   vector<int> vec;
	   
	   //从原点s到w的路径
	   path(w , vec);
	   
	   for(int i=0 ;i < vec.size() ;i++){
		   cout << vec[i];
		   if( i == vec.size() - 1 ){
			   cout << endl;
		   }else{
			   cout << "->";
		   }
	   }
	   
   }
   
   //s到w最短路径的长度
   int length(int w){
	   assert( w >= 0 && w < G.V() );
	   return ord[w];
   }
		
};