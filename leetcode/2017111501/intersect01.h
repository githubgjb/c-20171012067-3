
class Solution{

public:	
	vector<int> intersect(vector<int>& nums1,vector<int>& nums2){
		//元素和对应的频次
		map<int,int> record;
		
		//频次统计
		for(int i = 0 ; i < nums1.size() ; i++){
			record[nums1[i]] ++;
		}
		
		vector<int> resultVector;
		for(int i = 0; i < nums2.size() ; i++){
			//开始找交集
			if(record[nums2[i]] > 0){
				//放入返回集中
				resultVector.push_back( nums2[i] );
				
				//再减少,因为已经用到了,下次就失效了
				record[nums2[i]] --;
			}
		}
		
	    return resultVector;		
	}
};