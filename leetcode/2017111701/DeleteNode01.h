

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};


class Solution{

public:
	void deleteNode(ListNode* node){
		
		if(node == NULL){
			return;
		}
		
		if(node->next == NULL){
			delete node;
			node = NULL;
			return;
		}
		
		//先赋值
		node->val = node->next->val;
		
		ListNode* delNode = node->next;
		
		node->next = delNode->next;
		
		delete delNode;
		
		return;
	}	
};

int main(){
	
	return 0;
}

