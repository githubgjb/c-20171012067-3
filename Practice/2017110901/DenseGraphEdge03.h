
#include "Edge.h"

//稠密图 - 邻接矩阵

template <typename Weight>
class DenseGraph{

private:
	int n,m; //点和边
	bool directed; //方向//有向图,还是无向图
	
	//存放Edge<Weight>的指针,为了方便表达空
	//vector<vector<bool>> g;
	vector<vector<Edge<Weight> *>> g;
	
public:
   //多少个点,有向图无向图
   DenseGraph(int n, bool directed){
	   this->n = n;
	   this->m = 0;
	   this->directed = directed;
	    
		//这是一个矩阵
	   for(int i = 0 ; i<n ; i++){
		  //有n个元素,每一个元素都是false 
		  //g.push_back( vector<bool>(n,NULL) );
		  g.push_back( vector<Edge<Weight> *>(n,NULL) );
	   }  
   }
   
   ~DenseGraph(){
	   
	   for(int i = 0 ; i < n ; i++){
		   for(int j = 0 ; j < n ; j++){
			   if(g[i][j] != NULL){
				   delete g[i][j];
			   }
		   }
	   }
   }
   
   int V(){return n;} //返回点
   int E(){return m;} //返回边
   
   
   //给这个图添加一条边 //在顶点v顶点w之间建立一条边
   void addEdge(int v,int w,Weight weight){
	   
	   //首先要考虑v和w不越界
	   assert(v >= 0 && v < n);
	   assert(w >= 0 && w < n);
	   
	   if(hasEdge( v , w )){
		   //用新的边覆盖旧的边
		   delete g[v][w];
		   //如果是无向图,相反方向也删除
		   if( !directed ){
			   delete g[w][v];
		   }
		   m --;
	   }
	   
	   //g[v][w] = true;
	   g[v][w] = new Edge<Weight>(v , w , weight);
	   if(!directed){ //无向图
		   //g[w][v] = true;
		   g[w][v] = new Edge<Weight>(v , w , weight);
	   }
	   m ++;
   }
 
   //两点之间是否有边
   bool hasEdge(int v, int w){
	   //首先要考虑v和w不越界
	   assert(v >= 0 && v < n);
	   assert(w >= 0 && w < n);
	   return g[v][w] != NULL;
   }
   
   //显示
   void show(){
	   
	   for(int i=0 ; i < n ; i++){ //对点遍历
		   for(int j=0 ;j< n; j++){
			   if(g[i][j]){
				   cout << g[i][j] -> wt() << "\t";
			   }else{
				   cout << "NULL\t";
			   }			   
		   }
		   cout << endl;
	   }
	   
   }
   
   class adjIterator{
   private:
      DenseGraph &G; //图
	  int v;         //点
	  int index;     //索引

   public:   
	   adjIterator(DenseGraph &graph, int v): G(graph){
		   this->v = v;
		   this->index = -1;	   
	   }
	   
	   Edge<Weight>* begin(){
		   index = -1;
		   return next();
	   }
	   Edge<Weight>* next(){
		                          //图中顶点个数
		   for(index += 1; index < G.V() ; index++){
			   if(G.g[v][index]){
				   return G.g[v][index];
			   }
		   }
		   return NULL;
	   }
	   bool end(){
		   //是否大于等于顶点的个数
		   //说明这一行所有的都遍历完了
		   return index >= G.V();
	   }
   };
};