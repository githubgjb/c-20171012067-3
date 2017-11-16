using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};


class Solution{

public:
	ListNode* removeNthFromEnd(ListNode* head,int n){
		
		assert(n >= 0);
		
		ListNode* dummyHead = new ListNode(0);
		
		dummyHead->next= head;
		
		//要删除的元素的前一个元素是谁
		ListNode* p = dummyHead;
		ListNode* q = dummyHead;
		
		//移动q指针,
		for(int i = 0 ; i < n + 1 ; i++){
			assert(q);
			q = q->next;
		}
		
		while(q != NULL){
			//p是我们要删除的元素的前一个位置
			p = p->next;
			q = q->next;
		}
		//删除p所在指针前的后一个节点
		
		ListNode* delNode = p->next;
		//跨过了待删除节点
		p->next = delNode->next;
		
		delete delNode;
		
		ListNode* retNode = dummyHead->next;
		delete dummyHead;
		
		return retNode;
		
	}
};

int main(){
	
	return 0;
}