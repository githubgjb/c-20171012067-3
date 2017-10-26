
template <typename Key,typename Value>
class BST{

private:	
	struct Node{
	   Key key;
	   Value value;
	   Node *left;
	   Node *right;
	   
	   Node(Key key,Value value){
		   this->key = key;
		   this->value = value;
		   this->left = this->right = NULL;
	   }
	};
	Node *root; //根
	int count;//计数,有多少个节点

public:	
	BST(){
		root = NULL:
		count = 0;
	}
	~BST(){
		//TODO
	}
	int size(){
		return count;
	}
	bool isEmpty(){
		return count == 0;
	}
};