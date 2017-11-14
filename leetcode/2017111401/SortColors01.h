
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{

public:

	//时间复杂度: o(n)
	//空间复杂度: o(k),k为元素的取值范围
    void sortColors(vector<int>& nums){
		//统计0,1,2他们3个的个数
		//存放1,2,3三个元素的频率
		int count[3] = {0};		
		for( int i = 0 ; i < nums.size() ; i++ ){
			assert(nums[i] >= 0 && nums[i] <= 2);			
			count[nums[i]] ++;
		}
		
		//放入0
		int index = 0;
		for(int i=0 ; i < count[0] ; i++ ){
			nums[index++] = 0;
		}
		//放入1
		for(int i=0 ; i < count[1] ; i++ ){
			nums[index++] = 1;
		}
		//放入2
		for(int i=0 ; i < count[2] ; i++ ){
			nums[index++] = 2;
		}		
	}	
};

int main(){
	
	return 0;
}