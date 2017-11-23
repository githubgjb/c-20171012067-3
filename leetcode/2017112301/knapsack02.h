

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//tp5 权限  微信公众账号 微信支付  支付宝支付
//android - webview
//ios - webview

//归并排序,自底向上

class Knapsack01{

private:
	

public:
	//w重量 v价值 c容量
	int knapsack01(const vector<int> &w,const vector<int> &v,int C){
		
		assert( w.size() == v.size() );
		
		int n = w.size();
		
		if( n==0 ){
			return 0;
		}
		
		vector<vector<int>> memo(n,vector<int>(C+1,-1));
		
		//处理背包的容量
		for(int j = 0 ; j <= C ; j++){
			memo[0][j] = (j >= w[0] ? v[0] : 0 );
		}
		
		for(int i = 1 ; i < n ; i++ ){
			for(int j = 0 ; j < C ; j++){
				//0到i这些物品,且容积为j的背包
				memo[i][j] = memo[i-1][j];//把上一行的直接拿下来
				//物品能放进背包
				if(j >= w[i]){
					memo[i][j] = max( memo[i][j] , v[i] + memo[i-1][j-w[i]] );
				}
			}			
		}
		
		return memo[n-1][C];
		
	}
		
};

int main(){
	
	return 0;
}
