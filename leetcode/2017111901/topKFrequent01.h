
class Solution{
	
public:
	vector<int> topKFrequent(vector<int>& nums,int k){
		assert( k > 0 );
		
		//统计每个元素出现的频率
		unordered_map<int,int> freq;
		
		for(int i=0 ;i < nums.size() ;i++){
			freq[numsp[i]] ++;			
		}
		
		assert( k <= freq.size() );
		
		//扫描freq,维护当前出现频率最高的k个元素
		
		//小最堆
		//在优先队列中,按照频率排序,所以
		//数据对是(频率,元素)的形式
		priority_queue< pair<int,int> , vector<pair<int,int>>, greate<pair<int,int>>> pq;
		
		for(unordered_map<int,int>::iterator iter = freq.begin();
		iter != freq.end() ; iter ++){
			
			if(pq.size() == k){
				if(iter->second > pq.top().first){
					pq.pop();
					pq.push( make_pair(iter->second,iter->first) );
				}
				else{
					pq.push( make_pair(iter->second,iter->first) );
				}
			}
			
		}
		
		//访问一下优先队列
		vector<int> res;
		while( !pq.empty() ){
			res.push_back( pq.top().second );
			pq.pop();
		}
		
		return res;
		
		
	}
	
};