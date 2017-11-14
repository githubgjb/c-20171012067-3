
class Solution{

public:
	vector<int> intersection(vector<int>& nums1 , vector<int>& nums2 ){
		
		set<int> record;
		//记录一下每一个元素
		for(int i=0 ; i < nums1.size() ; i ++){
			//不能有重复元素,它可以自动去重
			record.insert( nums[i] );
		}
		
		//每个元素只记录一次
		set<int> resultSet;
		for(int i = 0 ; i < nums2.size() ; i++){
			//查找第二个元素//等于就不存在,不等就存在
			//每个元素只记录一次
			if(record.find( num2[i] ) != record.end() ){
				resultSet.insert( nums2[i] );
			}
		}
		//返回结果集
		vector<int> resultVector;
		
		//使用迭代器
		for(set<int>::iterator iter = resultSet.begin() ; iter != resultSet.end() ; iter ++){
			resultVector.push_back( *iter );
		}
		
		return resultVector;
	}	
};