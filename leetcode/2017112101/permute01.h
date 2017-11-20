
#include<iostream>

using namespace std;



class Solution{

private:

	vector<vector<int>> res;
	vector<bool> used;

	//p中保存了一个有index个元素的排列
	//向这个排列的末尾添加第index + 1,获得一个
	//有index+1个元素的排列
	void generatePermutation( const vector<int>& nums, int index , vector<int>& p ){
		
		//递归终止条件
		if(index == nums.size()){
			res.push_back(p);
			return;
		}
		
		//递归逻辑部分
		//index不能重复使用
		for(int i = 0 ; i < nums.size() ; i ++){
			//if(!(nums[i] 是否在 p)){
			if( !used[i] ){	
				//将nums[i]添加在P中
				p.push_back( nums[i] );
				used[i] = true;
				generatePermutation(nums , index+1 , p);
				
				//状态回溯
				//回去
				p.pop_back();//踢掉
				used[i] = false;
			}
			
		}
		return;	
	}
	
public:
	
	vector<vector<int>> permute(vector<int>& nums){
		
		res.clear();
		
		if( nums.size() == 0 ){
			return res;
		}
		
		//初始化
		used = vector<bool>(nums.size() , false);
		
		vector<int> p;
		
		//排列中一个元素都没有
		//有一上vector存储递归中生成的排列
		generatePermutation(nums , 0 , p);
		
		return res;
	}
		
};

int main(){
	
	return 0;
}
