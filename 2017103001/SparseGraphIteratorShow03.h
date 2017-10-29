
#include "Edge.h"

//稀疏图 -- 邻接表
template<typename Weight>
class SparseGraph{
	
private:
    int n,m; //点数和边数
	bool directed; //有向图无向图
	vector<vector<Edge<Weight> *>> g; //二维数组
	
public:
	SparseGraph(int n,bool directed){
		this->n = n;
		this->m = 0;
		this->directed = directed;
		for(int i=0 ;i<n i++){
			g.push_back( vector<Edge<Weight> *> );//放一个空的vector
		}		
	}
	
	~SparseGraph(){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<g[i].size() ;j++){
				delete[i][j];
			}
		}
	}
	int V(){return n;} //点
	int E(){return m;} //边
	
	void addEdge( int v,int w ,Weight weight){
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		g[v].push_back(new Edge(v,w,weight));
		if( v != w && !directed ){
			g[w].push_back(new Edge<Weight>(w,v,weight));
		}
		
		m ++;
	}
	
	bool hasEdge(int v,int w){
		//首先是不要越界
		assert( v>=0 && v<n );
		assert( w>=0 && w<n );
		
		for(int i=0 ; i<g[v].size() ; i++){
			if(g[v][i]->other(v) == w){
				return true;
			}
		}
		return false;
	}
	
	void show(){
		
		for(int i=0 ; i<n ; i++){
			cout<<"vertex" << i << ":\t";
			for(int j = 0; j< g[i].size();j++){
				//cout << g[i][j] << "\t";
				cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
			}
			cout<<endl;
		}
	}
	
	class adjIterator{
	private:
		SparseGraph &G; //存储图的引用
		int v;          //存储那一个点
		int Index;      //迭代到那里了
		
	public:
	    //构造列表初始化,因为是引用
		adjIterator(SparseGraph &graph, int v):G(graph){//那一个图,那一个点
			this->v = v;
			this->index = 0;
		}
		
		//这个点所在的第一个边
		Edge<Weight>* begin(){
			index = 0;
			if(G.g[v].size()){
				return G.g[v][0];
			}
			return NULL;
		}
		//访问这个节点的下一个边
		Edge<Weight>* next(){
			index ++;
			if( index < G.g[v].size() ){
				return G.g[v][index];
			}
			return NULL;
			
		}
		//没有边了
		bool end(){
			return index >= G.g[v].size();
		}
	};
};