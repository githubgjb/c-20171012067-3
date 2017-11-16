

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};

class Solution{

public:

    //链表的头指针 , 要删除节点包含的值,返回删除后的头指针
	ListNode* removeElements(ListNode* head,int val){
		//采用虚拟头节点
		ListNode* dummyHead = new ListNode(0);
		//它的值不重要,永远都不会访问
		dummyHead->next = head;
		
		
		ListNode* cur = dummyHead;
		while(cur->next != NULL ){
			
			//是不是我们想要删除掉的值
			if(cur->next->val = val){
				//删除cur->next
				//1.先保存一下待删除的节点
				ListNode* delNode = cur->next;
				
				//2.改变指针的指向
				cur->next = delNode->next;
				
				//3删除 释放掉内存
				delete delNode;
				
				//其它语言
				//delNode->next = NULL;
				
			}
			else{ //不是就继续向后找
				cur = cur->next;
			}			
		}

		ListNode* retNode = dummyHead->next;
		delete dummyHead;
		
		return retNode;		
	}
	
};

int main(){
	
	return 0;
}