
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
	//在以root为根节点的二叉树中
	//寻找和为sum的路径,返回这样的路径个数
	int pathSum(TreeNode* root,int sum){
		
		if(root == NULL){
			return 0;
		}
		
		//包含根节点,并且和为sum
		int res = findPath( root , sum );
		
		//不包含根节点
		res += pathSum(root->left , sum);
		res += pathSum(root->right, sum);
		
		return res;
	}

private:
	//在以node为根节点的二叉树中,
	//寻找包含node的路径和为sum
	//返回这样的路径个数
	int findPath( TreeNode* node,int sum ){
		
		if(node == NULL){
			return 0;
		}
		
		int res = 0;
		if(node->val == num){
			res += 1;
		}
		
		// x = num - node->val;
		// x 是我们要得到的值
		res += findPath( node->left,num - node->val );
		res += findPath( node->right,num - node->val );
		
		return res;
		
	}
	
	
};

int main(){
	
	return 0;
}
