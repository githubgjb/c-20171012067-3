


template <typename Graph,typename Weight>
//图的算法封装到一个类中
class ReadGraph{
	
private:

public:	
    //const文件类型的引用
	ReadGraph(Graph &graph,const string &filename){
		
		//文件读进流中来
		ifstream file(filename);
		
		//一行一行的读取
		string line;
		
		int V,E; //点和边
		
		assert( file.is_open() );
				
		//读取第一行,放到字符串中
		assert( getline(file , line) );
		
		//再line放入到另一个流中
		stringstream ss(line);
		
		//解析出点和边
		ss>>V>>E;
		
		//文件中的点数和图中的点数是一致的
		assert( v == graph.V() );
		
		for( int i=0 ; i<E ; i++){
			//读取第一行,放到字符串中
			assert( getline(file , line) );
		
			//再line放入到另一个流中
			stringstream ss(line);	

			int a,b;
			Weight w;
			
			ss>>a>>b>>W;
			
			assert(a>=0 && a < V);
			assert(b>=0 && b < V);
			
			graph.addEdge( a , b , w);
		}
		
	}
	
};