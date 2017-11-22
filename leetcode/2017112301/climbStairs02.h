

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//tp5 权限  微信公众账号 微信支付  支付宝支付
//android - webview
//ios - webview

class Solution{

private:



public:

	int climbStairs(int n){
		
		vector<int> memo(n+1,-1);
		
		memo[0] = 1;
		memo[1] = 1;
		for(int i=2 ; i <= n ;i++){
			memo[i] = memo[i-1] + memo[i-2]
		}
		
		return memo[n];
	}

		
};

int main(){
	
	return 0;
}
