

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
	vector<vector<int>> memo;

	//用[0...index]的物品,填充容积为c的背包
	//的最大价值
	int bestValue(const vector<int> &w,const vector<int> v,int index,int c){
		
		//递归终止条件
		//选不出物品 ,背包容量小于0了
		if(index < 0 || c <= 0){
			return 0;
		}
		
		if( memo[index][c] != -1 ){
			return memo[index][c];
		}
		
		int res = bestValue(w , v , index-1 , c);
		if( c >= w[index] ){
			res = max(res , v[index] + bestValue(w , v , index-1 , c - w[index]) );
		}
		memo[index][c] = res;
		
		return res;
	}	

public:
	//w重量 v价值 c容量
	int knapsack01(const vector<int> &w,const vector<int> &v,int C){
		int n = w.size();
		//二维数组初始化
		memo = vector<vector<int>>( n,vector<int>(C+1, -1) );
		return bestValue( w , v , n-1,C );
	}
		
};

int main(){
	
	return 0;
}
