

//时间复杂度 o(n^2)
//空间复杂度 o(n^2)

class Solution{
	
public:
	int forSumCount(vector<int>& A,vector<int>& B,vector<int>& C,vector<int>& D){
		
		//可以没有这个
		assert(A.size() == B.size() &&  B.size() == C.size() && C.size == D.size() );
		
		//c + d和的可能性
		//键:可能性  值:频率
		unordered_map<int , int> record;
		
		//初始化好查找表n^2
		for(int i = 0 ; i < C.size() ; i++){
			for(int j = 0 ; j < D.size() ; j++){
				record[C[i] + D[j]] ++;
			}
		}
		
		int res = 0;
		//再遍历A + B的可能性
		for(int i = 0 ; i < A.size() ; i++){
			for(int j = 0 ; j < B.size() ; j++){
				//开始找 四个数和为0
				if(record.find(0 - A[i] - B[j]) != record.end()){
					res += record[ 0 - A[i] -B[j] ];
				}			
			}
		}
		
		return res;		
		
	}
};