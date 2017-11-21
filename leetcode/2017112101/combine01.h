

#include<iostream>

using namespace std;



class Solution{

private:
	vector<vector<int>> res;

	//当前搜索的组合的元素
	//求解C(n,k),当前已经找到的组合存储在
	//c中,需要从start开始搜索新的元素
	void generateCombinations(int n,int k,int start,vector<int> &c){
		
		//结束条件
		if( c.size() == k ){
			res.push_back(c);
			return;
		}
		
		//递归过程
		for(int i = start ; i <= n ; i++){
			c.push_back(i);
			generateCombinations(n , k , i+1 , c);
			c.pop_back();
		}
		return;
	}
	
public:
	vector<vector<int>> combine(int n,int k){
		
		res.clear();
		
		//边界条件 4个数中找6个组合这是不可能的
		if( n <= 0 || k <= 0 || k > n){
			return res;
		}
		vector<int> c;
		generateCombinations(n,k,1,c);
		
		return res;
	}
		
};

int main(){
	
	return 0;
}
