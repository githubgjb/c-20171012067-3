

//时间复杂度:o(n)
//空间复杂度:o(1)
class Solution{

public:
	vector<int> twoSum(vector<int>& numbers,int target){
		
		//至少numbers有两个元素
		assert(numbers.size() >= 2 );
		
		int l = 0, r = number.size()-1;
		while(l < r){						
			if(numbers[l] + numbers[r] == target){
				//以1为开始的索引
				int res[2] = {l+1 , r+1};
				
				return vector<int>(res,res+2); //有两个元素
			}
			else if( numbers[l] + numbers[r] < target ){
				l++;
			}else{ // >
				r--;
			}
		}
		
		throw invalid_argument("The input has no solution.");
		
	}
};