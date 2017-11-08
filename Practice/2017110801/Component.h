
//模板类
template<typename Graph>
class Component{

private:
    Graph &G;
	//每一个节点是否被访问过了
	bool *visited; //bool型数组指针
	
	//记录有多少个联通分量
	int ccount;
	
	//每两个节点是否相联
	int *id; //数组的引用
	
	//每次对v这个节点进行深度优先遍历
	void dfs( int v ){
		
		visited[v] = true;
		
		//初始的时候count为0,
		//第一次运行
		id[v] = ccount;
		
		//G这个图,v这个节点
		typename Graph::adjIterator adj(G, v);
		
		//看一下v所有的临边
		for(int i = adj.begin() ; !adj.end() ; i = adj.next() ){
			
			//相临的节点有没有被访问过
			if(!visited[i]){
				dfs(i);
			}
		}
		
	}
	

//传入图的引用
public:
    //要初始化G
   Component(Graph &graph):G(graph){
	   
	   //开,这个图有多少个节点就开多少空间
	   visited = new bool[G.V()];
	   
	   //图中顶点的个数
	   id = new int[G.V()];
	   
	   ccount = 0;
	   
	   //初始的情况下每个元素都没有被访问过
	   for(int i=0 ; i<G.V() ; i++){
		   visited[i] = false;
		   id[i] = -1;
	   }
	   
	   //遍历每一个节点
	   for(int i=0 ; i<G.V() ; i++){
		   //如果没有被访问过的话
		   if(!visited[i]){
			   //进行深度优先遍历
			   dfs(i);
			   ccount ++;
		   }
	   }
   }
   
   ~Component(){
	   delete[] visited;
	   delete[] id;
   }
   
   //返回联通分量
   int count(){
	   return ccount;
   }
   
   bool isConnected(int v,int w){
	   assert(v >= 0 && v < G.V());
	   assert(w >= 0 && w < G.V());
	   return id[v] ==  id[w];
   }
  
	
};