

#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>

using namespace std;


class Solution{

private:
	

public:
	int findContentChildren(vector<int>& g,vector<int>& s){
		//排序从大到小
		//小朋友贪心指数
		sort(g.begin(),g.end(),greater<int>());
		//饼干大小排序
		sort(s.begin(),s.end(),greate<int>());
		
		//最大饼干,最贪心的小朋友
		int si = 0,gi = 0;
		//让多少个小朋友贪心了
		int res = 0;
		
		while(gi < g.size() && si < s.size()){
			//把最大块分给最贪心的朋友
			if(s[si] >= g[gi]){
				res ++;
				si ++;
				gi ++;
			}else{ //不能满足最贪心的小朋友
				
				//找下一个最贪心的小朋友
				//满足不了,就不满足
				gi ++;
			}
		}
		
		return res;
		
	}
};

int main(){
	
	return 0;
}
