

//时间复杂度 o(n)
//空间复杂度 o(1)

class Solution {

public:
	int minSubArrayLen(int s,vector<int>& nums){
		
		//初始状态下,滑块中没有任何数据
		int l = 0,r = -1; //num[l...r]为我们的滑动窗口
		
		//窗口中和是多少
		int sum = 0;
		
		//寻找到的当前子数组的最小长度
		//初始化为最大值,不可能取到的值
		int res = nums.size() + 1;
		
		//左边界还能取值
		while(l < nums.size() ){
			
			if( r+1 < nums.size() && sum < s ){
				r ++;
				sum += nums[r];
				//sum += nums[++r];
			}else{ // sum >= s
				sum -= nums[l++];
			}
			
			if( sum >= s ){
				//取一个最小值
				res = min(res,r-l+1);
			}			
		}
		
		//判断一下无解的情况
		if( res == nums.size() + 1 ){
			return 0;
		}

		return res;
	}	
};

int main(){
	
	return 0;
}