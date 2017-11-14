
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{

public:

	//时间复杂度: o(n)
	//空间复杂度: o(1)
	//遍历一遍
    void sortColors(vector<int>& nums){
		int zero = -1; // nums[0...zero] == 0
		int two  = nums.size();// nums[two...n-1] == 2
		
		for(int i = 0 ; i < two ; ){
			//000011112222
			if(nums[i] == 1){ //中间部分
				i++;
			}else if(nums[i] == 2){
				two--;
				swap(nums[i],nums[two]);
			}else{//num[i] == 0
				//为了严谨
				assert(nums[i] == 0);
				zero ++;
				swap(nums[zero] , nums[i] );
				i++;
			}			
		}
		
	}	
};

int main(){
	
	return 0;
}