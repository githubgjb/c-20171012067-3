
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};


class Solution{

public:
	ListNode* swapPairs(ListNode* head){
		
		//虚拟头指针
		ListNode* dummyHead = new ListNode(0);
		
		dummyHead->next = head;
		
		ListNode* p = dummyHead; //放在首部
		
		//确定还有节点可以交换
		while( p->next && p->next->next ){
			//进行节点的交换操作
			ListNode* node1 = p->next;
			ListNode* node2 = node1->next;
			
			//这对节点之后的节点 //next最差情况为空
			ListNode* next = node2->next;
			
			
			//具体交换
			node2->next = node1;
			node1->next = next;
			p->next = node2;
			
			//为了要进行下一次循环node1变成了第二位
			p = node1;
		}
		
		//要释放掉dummyHead
		ListNode* retNode = dummyHead->next;
		
		//释放内存
		delete dummyHead;
		
		return retNode;
	}
	
};

int main(){
	return 0;
}