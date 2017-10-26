
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
	
	void insert(Key key,Value value){
		
		root = insert(root,key,value);
		
	}

private:
	//向以node为根的二叉树搜索树中,插入节点(key,value)
	//返回插入节点后的二叉搜索树的根
	Node* insert(Node *node,Key key,Value value){
		
		//递归到底的情况
		if(node == NULL){//创建一个叶子节点
			count ++;
			return new Node(key,value);
		}
		
		if(key == node->key){
			node->value = value;
		}else if(key < node->key){
			node->left = insert(node->left , key , value);
		}else{ //Key > node->key
			node->right = insert(node->right , key , value);
		}
		
		return node;
	}
	
};