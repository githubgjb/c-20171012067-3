

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

	int max3(int a,int b,int c){
		return max(a,max(b,c));
	}

	//将n进行分割(至少分割两部分),可以获得的最大乘积
	int breakInteger(int n){
		//递归终止条件
		if(n == 1){
			return 1;
		}
		
		//运算过
		if(memo[n] != -1){
			return memo[n];
		}
		
		int res = -1;
		for(int i = 1 ; i <= n-1 ;i++){
			//分割成 i + (n-i)
			res = max3(res,i*(n-i),i * breakInteger(n-i));
		}
		
		memo[n] = res;
		
		return res;
	}

public:

	int integerBreak(int n){
		assert( n>=1 );//9-3 16:06
		
		memo = vector<int>(n+1,-1);
		
		return breakInteger(n);

	}

		
};

int main(){
	
	return 0;
}
