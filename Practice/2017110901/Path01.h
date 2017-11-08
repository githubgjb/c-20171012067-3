
template<typename Graph>
class Path{
	
private:
   Graph &G;
   int s; //原点
   bool* visited;
   int* from;//从那个节点过来的
   
   //每次对v这个节点进行深度优先遍历
	void dfs( int v ){
		
		visited[v] = true;		
		
		//G这个图,v这个节点
		typename Graph::adjIterator adj(G, v);
		
		//看一下v所有的临边
		for(int i = adj.begin() ; !adj.end() ; i = adj.next() ){
			
			//相临的节点有没有被访问过
			if(!visited[i]){
				//i这个节点是从v过来的
				from[i] = v;
				
				dfs(i);
			}
		}
		
	}
   
   
public:
   //从某一个点s的任意路径
   Path(Graph &graph,int s):G(graph){
	   
	   //算法初始化
	   assert(s >= 0 && s < G.V() );
	   
	   visited = new bool[G.V()];
	   from = new int[G.V()];
	   
	   for(int i=0 ; i< G.V() ; i++){
		   visited[i] =  false;
		   from[i] = -1;
	   }
	   
	   this->s = s;
	   
	   //寻路算法
	   dfs(s); //深度优先遍历
	   
   }
   
   ~Path(){
	   delete [] visisted;
	   delete [] from;	   
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


};

