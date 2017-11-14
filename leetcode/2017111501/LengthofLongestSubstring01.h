
class Solution {

public:

	int lengthOfLongestSubstring(string s){
		
		//有256个位置,初始为值0
		int freq[256] = {0};
		
		int l = 0, r = -1; //滑动窗口为s[l...r]
		
		//满足条件的子串的最长长度
		int res = 0;
		
		while( l < s.size() ){
			//还能移动的条件
			//右边界字符+1位置频率 是否等于0
			//还要保证值不越界
			if(r + 1 < s.size() && freq[s[r+1]] == 0 ){
				r++;
				freq[s[r]] ++;
			}
			else{
				requ[s[l++]] --;
			}
			
			//取最大值
			res = max( res , r-l+1 );
		}
			
		return res;
	}
		
};