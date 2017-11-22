

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;



class Solution{

private:	
	int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int m,n;
	vector<vector<bool>> visited;
	
	bool inArea(int x,int y){
		return x>=0 && x < m && y >= 0 && y < n;
	}
	
	//从grid[x][y]的位置开始,进行floodfill
	//保证(x,y)合法,且grid[x][y]是没被访问过的陆地
	void dfs(vector<vector<char>>& grid,int x,int y){
		
		visited[x][y] =  true;
		for(int i = 0 ; i<4 ; i++){
			int newx = x + d[i][0];
			int newy = y + d[i][1];
			
			//递归终止条件被融入到if语句之中
			//新的位置没有越界,并且没有被访问过,并且也是一个陆地
			if( inArea(newx,newy) && !visited[newx][newy] && grid[newx][newy] == '1'){
				dfs(grid , newx , newy);
			}
		}
		
		return;
	}


public:
	
	int numIslands(vector<vector<char>>& grid){
		
		m = grid.size(); //行
		if( m == 0 ){
			return 0;
		}
		n = grid[0].size();//列
		
		//visited赋值
		visited = vector<vector<bool>>(m,vector<bool>(n,false));
		
		//有多少个岛屿
		int res = 0;
		
		for(int i = 0; i<m ;i ++){
			for(int j = 0 ; j<n ; j++){
				//如果是陆地,并且没被访问过
				if(grid[i][j] == '1' && !visited[i][j]){
					res++;
					dfs(grid , i , j);
				}				
			}
		}
		
		return res;
		
	}
		
};

int main(){
	
	return 0;
}
