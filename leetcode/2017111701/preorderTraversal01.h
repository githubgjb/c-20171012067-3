
#include <iostream>
#include <cassert>
#include <string>
#include <stack>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
	
};

struct Command{
	
	string s ; //go,print
	TreeNode* node;
	Command(string s,TreeNode* node):s(s),node(node){}
	
};


class Solution{

public:
	//栈:后入先出
	
	//非递归的方式
	vector<int> preorderTraversal(TreeNode* root){
		
		vector<int> res;
		if( root == NULL ){
			return res;
		}
		
		//模拟计算机指令
		stack<Command> strack;
		
		//初始访问根节点
		stack.push( Command("go",root) );
		while( !stack.empty() ){
			
			//取出栈顶的元素
			Command command = stack.top();
			stack.pop();
			
			if( command.s == "print" ){
				res.push_back(command.node -> val);				
			}else{
				assert( command.s == "go" );
				
				if( command.node -> right ){
					stack.push( Command("go",command.node->right) );					
				}
				
				if( command.node -> left ){
					stack.push( Command("go",command.node->left) );					
				}
				stack.push( Command("print",command.node) );
			}
			
		}
		
		return res;
	}	
	
};

int main(){
	
	return 0;
}

