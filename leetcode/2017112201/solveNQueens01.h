

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;



class Solution{
	
private:
	vector<vector<string>> res;
	
	vector<bool> col; //纵向
	//对角线,2*n - 1
	vector<bool> dia1,dia2;
    
	//找一行的
	//尝试在一个n皇后问题中,摆放第index行的皇后位置
	void putQueen(int n,int index,vector<int> &row){
		
		//递归到底
		if( index == n ){
			res.push_back( generateBoard(n,row));
			return;
		}
		
		//递归回溯
		for(int i=0 ; i < n ; i++){
			//尝试将第index行的皇后摆放在第i列
			if( !col[i] && dia1[index+i] && !dia2[index-i+n-1]){
				row.push_back(i);
				col[i] = true;
				dia1[index+i] = true;
				dia2[index-i+n-1] = true;
				//继续向下递归
				putQueen(n,index+1,row);
				//回溯
				col[i] = false;
				dia1[index+i] = false;
				dia2[index-i+n-1] = false;
				row.pop_back();
			}			
		}
		return;
	}
	
	vector<string> generateBoard( int n, vector<int> &row ){
        assert( row.size() == n );
        vector<string> board(n, string(n, '.'));
        for( int i = 0 ; i < n ; i ++ )
            board[i][row[i]] = 'Q';
        return board;
    }

public:
	vector<vector<string>> solveNQueens(int n){
		
		res.clear();
		
		col = vector<bool>(n,false);
		dia1 = vector<bool>(2*n-1,false);
		dia2 = vector<bool>(2*n-1,false);
		
		vector<int> row;
		
		putQueen(n, 0, row);
		return res;
	}
		
};

int main(){
	
	return 0;
}
