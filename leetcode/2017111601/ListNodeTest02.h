
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};

//返回值为创建链表的头节点 //整型数组,元素的个数
ListNode* createLinkedList(int arr[], int n){
	
	if(n == 0){
		return NULL;
	}
	
	ListNode* head = new ListNode(arr[0]);
	
	//当前节点 //指向头指针
	ListNode* curNode =  head;
	
	for(int i = 1; i < n ; i++){
		curNode->next = new ListNode(arr[i]);
		//再将curNode指向新创建的节点
		curNode = curNode->next;
	}
	return head;
}

void printLinkedList(ListNode* head){
	
	ListNode* curNode = head;
	while(curNode != NULL){
		cout << curNode->val << " -> ";
		curNode = curNode->next;//节点向后移动
	}
	cout<<"NULL"<<endl;
	
	return;
}

void deleteLinkedList(ListNode* head){
	
	ListNode* curNode = head;
	while(curNode != NULL){
		//当前要释放的节点
		ListNode* delNode = curNode;
		//拿到下一个节点
		curNode = curNode->next;
		
		delete delNode;
	}
	
	return;
	
}

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
	
	int arr[] = {1,2,3,4,5};
	
	int n = sizeof(arr)/sizeof(int);
	
	ListNode* head = createLinkedList(arr,n);
	printLinkedList( head );
	
	ListNode* head2 = Solution().reverseList(head);
	printLinkedList( head2 );
	
	//内存管理
	deleteLinkedList( head2 );
	
	return 0;
}