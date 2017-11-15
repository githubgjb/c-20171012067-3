

class Solution{

public:     
                                //数据对x,y
	int numberOfBoomerangs(vector<pair<int,int>& points>){
		//记录有多少个三元组
		int res = 0;
		for( int i = 0 ; i<points.size() ; i++ ){
			//再遍历一下枢纽点i,再需要查找表
			//距离,距离出现的频率
			//其余的点到i的距离,以及出现的频次
			unordered_map<int,int> record;
			
			//遍历一下其它点
			for(int j = 0 ; j < points.size() ; j++){
				//找到不同的点
				if( j != i ){
					//记录距离,计算两个点的距离 //dis这个方法就不写了
					record[ dis(points[i],points[j]) ] ++;
				}
			}
			
		}		
	}	
};

4-6 题没看懂