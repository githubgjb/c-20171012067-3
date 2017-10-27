
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
		destory( root );
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
	
	bool contain(Key key){
		
		return contain(root,key);
	}
	
	value* search(Key key){
		
		return search(root , key);
	}
	
	//前序遍历
	void preOrder(){
		preOrder(root);
	}
	
	//中序遍历
	void inOrder(){
		inOrder(root);
	}
	
	//后序遍历
	void postOrder(){
		postOrder(root);
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
	
	//查看以node为根的二叉搜索树中是否包含
	//键值为key的节点
	bool contain(Node* node,Key key){
		
		//递归到底的情况
		if(node == NULL){
			return false;
		}
		
		if(key == node->key){
			return true;
		}
		else if(key < node->key){
			return contain(node->left,key);
		}else{//key > node->key
			return contain(node->right,key);
		}
	}
	
	//在以node为根的二叉搜索树中查找Key所对应的
	//value
	Value* search(Node* node,Key key){
		//递归到底的情况
		if(node == NULL){
			return NULL;
		}
		if(key == node->key){
			return &(node->value);//返回value值的地址
		}else if(key < node->key){
			return search(node->left,key);
		}else{//key > node->key
			return search(node->right,key);
		}
		
	}
	
	//对以node为根的二叉搜索树进行前序遍历
	void preOrder(Node* node){
		
		if(node != NULL){
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}	
	}
	
	//对以node为根的二叉搜索树进行中序遍历
	void inOrder(Node* node){
		if(node != NULL){
			inOrder(node->left);
			cout<<node->key<<endl;
			inOrder(node->right);
		}
	}
	
	//对以node为根的二叉搜索树进行后序遍历
	void postOrder(Node* node){
		if(node != NULL){			
			postOrder(node->left);
			postOrder(node->right);
			cout<<node->key<<endl;
		}
	}
	
	//对二叉树释放空间
	void destory(Node* node){		
		if(node != NULL){
			destory(node->left);
			destory(node->right);
			
			delete node;
			count --;
		}		
	}
	
};