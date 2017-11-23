

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
	//memo[i] 表示考虑抢劫nums[i....n) 所能获得的最大收益
	vector<int> memo; 
	
	//考虑抢劫nums[index...nums.size())这个
	//范围的所有房子
	int tryRob(vector<int> &nums,int index){
		
		//递归结束条件
		if( index >= nums.size() ){
			return 0;
		}
		
		if(memo[index] != -1){
			return memo[index];
		}
		
		int res = 0;
		//递归过程
		for(int i = index ; i < nums.size() ; i++){
			res = max(res , nums[i] + tryRob(nums, i+2));
		}
		memo[index] = res;
		
		return res;
	}

public:
	int rob(vector<int>& nums){
		
		memo = vector<int>(nums.size(),-1);
		
		return tryRob(nums, 0);
	}		
};

int main(){
	
	return 0;
}
