

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//tp5 权限  微信公众账号 微信支付  支付宝支付
//android - webview
//ios - webview

class Solution{

private:
	vector<int> memo;

	int calcWays(int n){
		/*
		if( n == 0 ){
			return 1;
		}
		*/
		//递归到底,只有一阶台阶
		if( n==0 || n==1 ){
			return 1;
		}
		
		//只有两阶
		/*
		if( n==2){
			return 2;
		}
		*/
		
		
		//return calcWays(n-1) + calcWays(n-2);
	
		if(memo[n] == -1){
			memo[n] = calcWays(n-1) + calcWays(n-2);
		}
		return memo[n];
	}
	
public:

	int climbStairs(int n){
		
		memo = vector<int>(n+1,-1);
		
		return calcWays(n);
	}

		
};

int main(){
	
	return 0;
}
