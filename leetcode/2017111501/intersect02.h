
class Solution{

public:	
	vector<int> intersect(vector<int>& nums1,vector<int>& nums2){
		//元素和对应的频次 
		//C++中map是有默认值的,为0
		map<int,int> record;
		
		//频次统计
		for(int i = 0 ; i < nums1.size() ; i++){
			//record[nums1[i]] ++;
			if(record.find(nums1[i]) == record.end()){
				//                       键     值 
				record.insert(make_pair(nums1[i],1));
			}else{
				record[nums1[i]] ++;
			}
		}
		
		vector<int> resultVector;
		for(int i = 0; i < nums2.size() ; i++){
			//开始找交集
			if( record.find(nums2[i]) != record.end() && record[nums2[i]] > 0){
				//放入返回集中
				resultVector.push_back( nums2[i] );
				
				//再减少,因为已经用到了,下次就失效了
				record[nums2[i]] --;
				
				//真正的删除
				if(record[nums2[i]] == 0){
					record.erase( nums2[i] );
				}
			}
		}
		
	    return resultVector;		
	}
};