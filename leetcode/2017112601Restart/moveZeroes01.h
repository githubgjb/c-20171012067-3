

#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>

using namespace std;


class Solution{

private:
	

public:

    //时间复杂度:o(n)
    //空间复杂度:o(n)
	void moveZeroes(vector<int>& nums){
		
		vector<int> nonZeroElements;
		
		for(int i=0 ; i<nums.size() ;i++){
			//把非0元素装入nonZeroElements向量中
			if(nums[i]){
				nonZeroElements.push_back(nums[i]);
			}
		}
		
		//再把nonZeroElements元素放回去中
		for(int i=0;i<nonZeroElements.size(); i++){
			nums[i] = nonZeroElements[i];
		}
		
		//剩下的都放0
		for(int i= nonZeroElements.size(); i<nums.size();i++){
			nonZeroElements[i] = 0;
		}
		
	}
};

int main(){
	//sizeof 返回内存的字节数
	
	int arr[] = {0,1,0,3,12};
	
	//根据数组生成vector
	vector<int> vec(arr,arr + sizeof(arr)/sizeof(int));
	
	Solution().moveZeroes(vec);
	
	//打印
	for(int i=0 ; i<vec.size() ; i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
