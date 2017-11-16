

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
		
		//头指针要特殊化处理
		//这段代码可以简化
		/*
		if( head == NULL ){
			return NULL;
		}
		*/
		
		//单独对头节点处理
		//如果下一个删除的还是头节点呢,所以用循环
		//if( head->val = val ){
		while( head != NULL && head->val = val ){
			ListNode* delNode = head;
			head = delNode->next;
			delete delNode;
		}
		
		//上面运行完之后要是空呢
		if(head == NULL){
			return NULL;
		}		
		
		ListNode* cur = head;
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
		
		return head;		
	}
	
};

int main(){
	
	return 0;
}