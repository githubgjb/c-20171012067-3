
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
	
};

class Solution {

public:
	vector<vector<int>> levelOrder(TreeNode* root){
		
		vector<vector<int>> res;
		if(root == NULL){
			return res;
		}
		
		//层序遍历二叉树
		//node节点在第几层
		queue< pair<TreeNode*,int> > q;
		
		//创建一个节点
		q.push( make_pair( root, 0 ) );
		while( !q.empty() ){
			
			//取出队首
			TreeNode* node = q.front().first;
			int level = q.front().second;
			
			//出队
			q.pop();
			
			//判断一下,是否已经包含当前层
			//等于就是还没有
			if(leve == res.size()){
				res.push_back( vector<int>() );
			}
			
			res[level].push_back(node->val);
			
			
			//左节点入队
			if(node->left){
				q.push(make_pair(node->left , level + 1));
			}
			
			//右节点入队
			if(node->right){
				q.push(make_pair(node->right , level + 1));
			}
			
		}
		
		return res;
				
	}
};


int main(){
	
	return 0;
}