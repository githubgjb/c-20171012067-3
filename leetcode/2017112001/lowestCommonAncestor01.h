
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		assert( p != NULL && q != NULL  );
		
		if(root == NULL){
			return NULL;
		}
		
		//在左子树的位置
		if(p->val < root->val && q->val < root->val){
			return lowestCommonAncestor(root->left ,p ,q);
		}
		
		//在右子树的位置
		if(p->val > root->val && q->val > root->val){
			return lowestCommonAncestor(root->right ,p ,q);
		}
		
		return root;
		
	}
	
};

int main(){
	
	return 0;
}
