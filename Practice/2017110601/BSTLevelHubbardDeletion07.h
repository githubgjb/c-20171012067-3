

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
	   
	   Node(Node *node){
		   this->key = node->key;
		   this->value = node->value;
		   this->left = node->left;
		   this->right = node->right;
	   }
	   
    };
	Node *root; //根
	int count;  //计数   

public:
	BST(){
		root = NULL:
		count = 0;
	}
	
	~BST(){
		
		destroy( root );
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
	
	bool contain(Key key){
		return contain(root , key);
	}
	
	Value* search(Key key){
		//以某个节点为根的key的值
		return search( root , key );
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
	
	//层序遍历
	void levelOrder(){
		
		queue<Node*> q;
		q.push(root);
		while( !q.empty() ){
			//取出队首的元素
			Node *node = q.front();
			//出队
			q.pop();
			
			cout << node->key << endl;
			
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
		}		
	}
	
	//寻找最小的键值
	Key minimum(){
		assert( count != 0 );
		Node* minNode = minimum( root );
		
		return minNode->key;
	}
	
	//寻找最大键值
	Key maximum(){
		assert( count != 0 );
		Node* maxNode = maximum( root );
		
		return maxNode->key;
	}
	
	//从二叉树中删除最小值所在节点
	void removeMin(){
		
		if(root){ //根不为空
			root = removeMin( root );
		}
		
	}
	
	void removeMax(){
		
		if(root){
			
			root = removeMax( root );
		}
		
	}
	
	//从二叉树中删除键值为key的节点
	void remove(Key key){
		root = remove(root , key);
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

    // 查看以node为根的二叉搜索树中是否包含键值
    //为key的节点
	bool contain(Node* node,Key key){
		
		//递归到底
		if(node == NULL){
			return false;
		}
		
		if(key == node->key){
			return true;
		}else if(key < node->key){
			return contain(node->left,key);
		}else{// key > node->key
			return contain(node->right,key);
		}
	}
	
	//在以node为根的二叉搜索树中查找key所对应的value
	Value* search(Node* node,Key key){
		
		//递归到底
		if(node == NULL){
			return NULL:
		}
		
		if(key == node->key){
			
			return &(node->value);//返回value值对应的地址			
		}else if(key < node->key){
			return search(node->left , key);
		}else{//key > node->key
			return search(node->right , key);
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
			cout<< node->key << endl;
			inOrder(node->right);
		}
	}
	
	//以对node为根的二叉搜索树进行后序遍历
	void postOrder(Node* node){
		
		if(node != NULL){
			postOrder(node->left);			
			postOrder(node->right);
			cout<< node->key << endl;
		}
	}
	
	void destroy(Node* node){
		
		if(node != NULL){
			destory(node->left);
			destory(node->right);
			
			delete node;
			count --;
		}
		
	}
	
	//在以node为根的二叉搜索树中,返回
	//最小键值的节点.
	Node* minimum(Node* node){
		
		if(node->left == NULL){
			return node;
		}
		
		return minimum(node->left);
	}
	
	Node* maximum(Node* node){
		
		if(node->right == NULL){
			return node;
		}
		
		return maximum(node->right);
	}
	
	
	//删除掉以node为根的二分搜索树中的最小节点
	//返回删除节点后新的二分搜索树的根
	Node* removeMin(Node* node){
		//找到  ->  返回并删除
		if(node->left == NULL){
			Node* rightNode = node->right;
			delete node;
			count --;
			
			return rightNode;
		}
		
		node->left = removeMin(node->left);
		return node;
	}

	Node* removeMax(Node* node){
		
		if(node->right == NULL){
			
			Node* leftNode = node->left;
			delete node;
			count --;
			
			return leftNode;
		}
		
		node->right = removeMax(node->right);
		
		return node;
	}
	
	Node* remove(Node* node,Key key){
		
		//递归到底
		if(node == NULL){
			return NULL;
		}
		
		//找的过程
		if(key < node->key){
			node->left = remove(node->left , key);
			return node;
		}
		else if(key > node->key){
			node->right = remove(node->right,key);			
		}//要处理的
		else{//key == node->key
			
			//只有右孩子
			if(node->left == NULL){
				Node *rightNode = node->right;
				delete node;
				count --;
				return rightNode;				
			}
			
			//只有左孩子
			if(node->right == NULL){
				Node *leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			
			//左右两孩子都不为空
			//node->left != NULL && node->right != NULL
			//Node *delNode = node; //要删除的node先保存下来
			//右节点的最小值
			Node *successor = new Node(minimum(node->right));
			coutn ++;
			
			
			successor->right = removeMin(node->right);
			successor->left = node->left;
			
			delete node;
			count --;
			
			return successor;
		}
		
		
	}

	
};
	
		
};

int main() {
	
	
}