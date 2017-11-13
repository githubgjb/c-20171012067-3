
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	
	//时间复杂度:o(n)
	//空间复杂度:o(n)
	void moveZeroes(vector<int> & nums){
		vector<int> nonZeroElements; //放非0元素
		
		//取出非0
		for(int i=0 ; i < nums.size ; i++){
			if(nums[i]){
				nonZeroElements.push_back( nums[i] );
			}
		}
		
		//赋值
		for(int i=0 ; i<nonZeroElements.size() ; i++){
			nums[i] = nonZeroElements[i];
		}
		
		//放0
		for(int i = nonZeroElements.size() ; i<nums.size() ;i++){
			nums[i] = 0;
		}
		
	}
		
};

int main(){
	
	int arr[] = {0,1,0,3,12};
	
	//根据数组生成vector
	
	vector<int> vec(arr,arr + sizeof(arr)/sizeof(int));
	
	Solution().moveZeroes( vec );
	
	for(int i=0 ; i<vec.size() ; i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}