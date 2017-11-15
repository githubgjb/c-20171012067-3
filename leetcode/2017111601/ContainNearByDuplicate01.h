
//时间复杂度:o(n)
//空间复杂度:o(k)

class Solution{
	
public:
	bool containsNearbyDuplicate(vector<int>& nums,int k){
		
		//滑动窗口的长度是固定的
		unordered_set<int> record;
		
		for(int i = 0 ; i < nums.size() ; i++ ){
			
			//找到的情况下
			if(record.find(nums[i]) != record.end() ){
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