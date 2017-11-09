
#include "MinHeap.h"
using namespace std;

template<typename Graph,typename Weight>
class LazyPrimMST{
	
private:
   Graph &G;
   MinHeap<Edge<Weight>> pq;
	
   //这个点是不是被标记了
   bool *marked;   
   
   //最小生成树就是V-1条边
   vector<Edge<Weight>> mst;
   
   //权值
   Weight mstWeight;
   
   void visited(int v){
	   
	   //还是false的,没有访问过的
	   assert( !marked[v] );
	   
	   marked[v] = true;
	   
	   //遍历临边
	   typename Graph::adjIterator adj(G,v);
	   for(Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
		   //另外一个点没有被访问过,找到了横切边
		   if(!marked[e->other(v)]){
			   pq.insert(*e);
		   }
	   }
	   
   }
	
public:

   LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){
	   
	   marked = new bool[G.V];
	   for(int i = 0 ; i< G.V() ;i++){
		   marked[i] = false;
	   }
	   mst.clear();
	   
	   //Lazy Prim
	   visit(0);
	   
	   //不断的扩展红色节点
	   while( !pq.isEmpty() ){
		   //取出优先队列里最小的边
		   Edge<Weight> e = pq.extractMin();
		   //去掉不是横切边
		   if(marked[e.v] == marked[e.w]){
			   continue;
		   }
		   
		   mst.push_back( e );
		   //是不是蓝色的,是,访问
	       if(!marked[e.v]){
			  visite( e.v() );  
		   }else{
			  visite( e.w() );
		   }		   
	   }
	   
	   mstWeight = mst[0].wt();
	   for(int i = 1 ; i< mst.size() ; i++){
		   mstWeight += mst[i].wt();
	   }
	   
   }
   
   ~LazyPrimMST(){
	   
	   delete[] marked;	   
   }

   vector<Edge<Weight>> mstEdges(){
	   return mst;
   }
   
   Weight result(){
	   return mstWeight;
   }
   
};