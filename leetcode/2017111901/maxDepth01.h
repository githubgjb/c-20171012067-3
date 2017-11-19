
#include<iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
	
};

class Solution{
	
public:
	int maxDepth(TreeNode* root){
		//递函数包含两部分
		//1.终止条件
		//2.递归过程
		
			
		//1.终止条件
		if(root == NULL){
			return 0; //高度是0
		}
		
		
		//2.递归过程
		int leftMaxDepth = maxDepth( root->left );
		int rightMaxDepth = maxDepth( root->right );
		
		//1是谁,是1当前节点
		return max(leftMaxDepth , rightMaxDepth) + 1;
		
	}
	
};

int main(){
	
	return 0;
}
