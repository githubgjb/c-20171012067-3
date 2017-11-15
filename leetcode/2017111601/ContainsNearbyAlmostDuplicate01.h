
//时间复杂度:o(nlogn)
//空间复杂度:o(k)

class Solution{
	
public:
	bool containsNearbyDuplicate(vector<int>& nums,int k,int t){
		
		//滑动窗口的长度是固定的
		//set<int> record;
		set<long long> record;
		
		for(int i = 0 ; i < nums.size() ; i++ ){
			
			/*
			//找到的情况下
			if(record.find(nums[i]) != record.end() ){
				return true;
			}
			*/
			
			//找最小值
			//查找表中最小值
			/*
			if(record.lower_bound(nums[i] - t) != record.end() 
				&& *record.lower_bound(nums[i] - t) <= nums[i] + t){
				return true;
			}
			*/
			if(record.lower_bound( (long long)nums[i] - (long long)t) != record.end() 
				&& *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t){
				return true;
			}
			
			record.insert( nums[i] );
			
			//保持record中最多有k个元素
			if( record.size() == k + 1 ){
				//删除掉最左侧数据
				record.erase( nums[i - k] );
			}
			
		}
		
		return false;
		
	}	
};