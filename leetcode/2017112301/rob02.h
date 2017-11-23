

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
	

public:
	int rob(vector<int>& nums){
		int n = nums.size();
		
		if( n==0 ){
			return 0;
		}
		
		//memo[i] 表示考虑抢劫nums[i....n-1] 所能获得的最大收益
		vector<int> memo(n,-1);
		//只有一个房子的时候,肯定偷
		memo[n-1] = nums[n-1];
		for(int i = n - 2 ; i >= 0 ; i--){
			//memo[i]
			for(int j = i ; j < n ; j++){
				memo[i] = max(memo[i],nums[j] + (j+2 < ? memo[j+2] : 0));
			}			
		}
		return memo[0];
	}		
};

int main(){
	
	return 0;
}
