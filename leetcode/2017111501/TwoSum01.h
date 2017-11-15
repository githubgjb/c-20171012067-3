
class Solution{

//时间复杂度:o(n)
//空间复杂度:o(n)

public:
	vector<int> twoSum(vector<int>& nums , int target){
		
		//hash
		unordered_map<int,int> record;
		
		for(int i = 0 ; i < nums.size() ; i++ ){
			//数据nums的值当键//不能这么做,有问题
			//record[[nums[i]]] = i;
			
			//确定要查找的元素
			int complement= target - nums[i];
			
			//在当前的查找表中找complement
			
			//能找到
			if(record.find( complement ) != record.end() ){
				//返回的是索引
				int res[2] = { i , record[complement] };
				return vector<int>( res, res+2 );
			}
			
			//没找到才放
			record[nums[i]] = i;
			
		}
		
		throw invalid_argument("the input has no solution");
		
	}
};