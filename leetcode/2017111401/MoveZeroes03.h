
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
		
	//时间复杂度:o(n)
	//空间复杂度:o(1)
	void moveZeroes(vector<int> & nums){
		
		//nums中,[0...k)的元素均为非0元素
		int k = 0;
		
		//遍历到第i个元素后,保证[0...i]中所有非0元素
		//都按照序顺排列在[0....k)中
		//同时,[k...i]为0
		for(int i=0 ; i<nums.size() ;i++){
			//是非0元素
			if(nums[i]){
				//要是都是0呢,就不用交换了
				if(i != k){
					swap(nums[k++] = nums[i]);
				}else{ // i==k
					k++;
				}				
			}
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