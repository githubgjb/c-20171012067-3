
#include "Edge.h"

//稠密图 -- 邻接矩阵
template <typename Weight>
class DenseGraph{
	
private:
    int n,m; //点数和边数
	bool directed; //有向图无向图
	vector<vector<Edge<Weight> *>> g; //二维数组
	
public:
	DenseGraph(int n,bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for(int i=0 ; i<n ; i++){
			g.push_back(vector<Edge<Weight> *>(n,NULL));
		}
	}
	
	~DenseGraph(){
		 for(int i=0 ; i<n ; i++){
			 for(int j = 0 ; j<n ;j++){
				if(g[i][j] != NULL){
					delete g[i][j];
				}
			 }
		 }
		
	}
	
	int V(){return n;} //点
	int E(){return m;} //边
	
	void addEdge(int v,int w , Weight weight){//两个顶点索引,几行,几列
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		if(hasEdge( v , w )){
			delete g[v][w];
			if(!directed){
				delete g[w][v];
			}
			m --;
		}
		
		g[v][w] = new Edge<Weight>(v,w,weight);
		if(!directed){ //如果是无向图
			g[w][v] = new Edge<Weight>(v,w,weight);
		}
		m++;//增加一条边
	}
	
	//是否存在边
	bool hasEdge(int v,int w){
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		return g[v][w] != NULL ;
	}
	
	void show(){
		
		for(int i=0 ; i<n ; i++){
			for(int j =0 ; j<n ; j++){
				if(g[i][j]){
					cout<<g[i][j]->wt()<<"\t";
				}else{
					cout<<"NULL\t";
				}				
			}
			cout<<endl;
		}		
	}
	
	class adjIterator{
	private:
		DenseGraph &G; //存储图的引用
		int v;          //存储那一个点
		int Index;      //迭代到那里了
		
	public:
	    //构造列表初始化,因为是引用
		adjIterator(DenseGraph &graph, int v):G(graph){//那一个图,那一个点
			this->v = v;
			this->index = -1;
		}
		
		//这个点所在的第一个边
		Edge<Weigth>* begin(){
			
			index = -1;
			return next();
			
		}
		//访问这个节点的下一个边
		Edge<Weigth>* next(){
			for(index +=1 ; index< G.V() ; index++){
				if(G.g[v][index]){
					return G.g[v][index];
				}
			}
			return NULL;
			
		}
		//没有边了
		bool end(){
			return index >= G.V();
		}
	};
	
};