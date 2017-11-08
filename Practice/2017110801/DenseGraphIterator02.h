
//稠密图 - 邻接矩阵
class DenseGraph{

private:
	int n,m; //点和边
	bool directed; //方向//有向图,还是无向图
	vector<vector<bool>> g;
	
public:
   //多少个点,有向图无向图
   DenseGraph(int n, bool directed){
	   this->n = n;
	   this->m = 0;
	   this->directed = directed;
	    
		//这是一个矩阵
	   for(int i = 0 ; i<n ; i++){
		  //有n个元素,每一个元素都是false 
		  g.push_back( vector<bool>(n,false) );
	   }  
   }
   
   ~DenseGraph(){
	   
   }
   
   int V(){return n;} //返回点
   int E(){return m;} //返回边
   
   
   //给这个图添加一条边 //在顶点v顶点w之间建立一条边
   void addEdge(int v,int w){
	   
	   //首先要考虑v和w不越界
	   assert(v >= 0 && v < n);
	   assert(w >= 0 && w < n);
	   
	   if(hasEdge( v , w )){
		   return;
	   }
	   
	   g[v][w] = true;
	   if(!directed){ //无向图
		   g[w][v] = true;
	   }
	   m ++;
   }
 
   //两点之间是否有边
   bool hasEdge(int v, int w){
	   //首先要考虑v和w不越界
	   assert(v >= 0 && v < n);
	   assert(w >= 0 && w < n);
	   return g[v][w];
   }
   
   //7-3 10:01
};