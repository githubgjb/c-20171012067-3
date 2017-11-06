

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
		   this->left = this ->right = NULL;
	   }
	Node *root; //根
	int count;  //计数   

public:
	BST(){
		root = NULL:
		count = 0;
	}
	
	~BST(){
		//TODO:		
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	void insert(Key key, Value value){
		//插入节点后二叉树的根
		root = insert(root,key,value);
	}

private:
	
	//返回的是一个指针
	Node* insert(Node *node,Key key,Value value){
		
		//递归到底的情况
		if(node == NULL){
			count ++;
			return new Node(key,value);
		}
		
		if( key == node->key ){
			node->value = value;
		}else if(key < node->key){
			node->left = insert(node->left , key , value);
		}else{//key > node->key
			node->right = insert(node->right,key,value);
		}
		return node;
	}	
};
	
		
};

int main() {
	
	
}