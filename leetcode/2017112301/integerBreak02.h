

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//tp5 权限  微信公众账号 微信支付  支付宝支付
//android - webview
//ios - webview

//归并排序,自底向上

class Solution{

private:
	vector<int> memo;

	int max3(int a,int b,int c){
		return max(a,max(b,c));
	}



public:

	int integerBreak(int n){
		assert( n>=2 );
		//memo[i]表示将数字i分割(至少分割两部分)
		//后得到的最大乘积
		vector<int> memo(n+1,-1);
		
		//自底向上解决,动态规划(自底向上,记忆搜索)
		memo[1] = 1;
		
		for(int i = 2 ;i <= n ; i++){
			//求解memo[i]
			for(int j=1 ; j <= i-1 ;i++){
				//j + (i-j)
				memo[i] = max3(memo[i],j*(i-j),j*memo[i-j]);
			}
		}
		return memo[n];

	}

		
};

int main(){
	
	return 0;
}
