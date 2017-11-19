
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
	TreeNode* invertTree(TreeNode* root){
		
		//1.终止条件
		if(root == NULL){
			return NULL;
		}
		
		//2.递归过程
		
		//反转左子树
		//反转右子树
		
		invertTree( root->left );
		invertTree( root->right );
		
		//最细节的部份
		swap(root->left,root->right);
		
		return root;
	}	
};

int main(){
	
	return 0;
}
