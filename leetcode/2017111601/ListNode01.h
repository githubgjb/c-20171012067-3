
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};

class Solution{
	
	ListNode* reverseList(ListNode* head){
		
		//前
		ListNode* pre = NULL;
		//中 当前
		ListNode* cur = head;
		//后
		//ListNode* next = cur->next;
		while( cur != NULL ){
			//解决了非空判断
			ListNode* next = cur->next;
			
			//开始更改指针
			
			cur->next = pre;
			pre = cur;
			cur = next;
			
		}

		return pre;
	}	
};

int main(){
	
	return 0;
}