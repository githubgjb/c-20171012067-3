
using namespace std;

class Solution{
public:
    //多少个完全平方数,和为n
	// 12 = 4 + 4 + 4
	// 12 = 2^2 + 2^2 + 2^2
	int numSquares(int n){
		
		//n是一个正整数
		assert( n > 0 );
		
		//第几个数字,几段路径
		queue< pair<int,int> > q;
		
		//第一个数字,一步都没有走就到达了
		q.push( make_pair(n,0) );
		
		//处理冗余
		//n+1个数字有没有被访问过
		vector<bool> visited(n+1, false);
		visited[n] = true;
		
		while( !q.empty() ){
			
			int num = q.front().first;
			int step = q.front().second;
			q.pop();
			
			//这个数字还能承受一个完全平方数
			//for(int i=1 ; num - i*i >= 0 ; i++){
			for(int i=1 ;; i++){
				int a = num - i*i ;
				if(a < 0){
					break;
				}
				if(a == 0){
					return step + 1;
				}
				if(!visited[a]){
					q.push( make_pair( a ,step + 1 ) );
					visited[a] = true;
				}		
			}
			
		}
		throw invalid_argument("No Solution.");
				
	}
	
	
};

int main(){
	
}