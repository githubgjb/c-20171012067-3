
template<typename Graph>
class ReadGraph{
	
public:
	ReadGraph(Graph &graph,const string &filename){
		
		ifstream file(filename); //把文件读进流中
		string line;             //一行一行读取
		int V,E;                 //点和边
		
		assert( file.is_open() );//确定文件被打开
		
		assert( getline(file , line) );//确定能读取第一行
		
		stringstream ss(line);
		
		ss>>V>>E;//解析出来
		
		assert(V == graph.V() );//文件中点数和图中点数是一致的
		
		for(int i=0 ; i<E ;i++){
			
			assert( getline(file , line) );//确定能读取第一行		
			stringstream ss(line);
			
			int a,b;
			ss>>a>>b;
			//防止越界
			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			
			//加入图中
			graph.addEdge(a , b);
		}
		
	}
};

int main(){
	string = filename = "testG1.txt";
	
	SparseGraph g1(13, false); //13个节点,无向图
	ReadGraph<SparseGraph> readGraph1(g1 , filename);	
	g1.show();
	
	cout<<endl;
	
	DenseGraph g2(13 , false);
	ReadGraph<DenseGraph> readGraph2(g2 , filename);
	g2.show();
	
	return 0;
}