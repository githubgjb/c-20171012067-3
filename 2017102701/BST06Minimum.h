#include<queue>

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
	
	//层序遍历
	void levelOrder(){
		
		queue<Node*> q;
		q.push(root);
		
		while( !q.empty() ){
			
			Node *node = q.front();//取出队首的元素
			q.pop();//出队
			
			cout<<node->key<<endl;
			
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
		assert(count != 0);
		Node* minNode = minimum( root );
		return minNode->key;
	}
	
	//寻找最大的键值
	Key maxmum(){
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}
	
	//从二叉树中删除最小值所在节点
	void removeMin(){
		if(root){
			root = removeMin( root );
		}
	}
	
	//从二叉树中删除最值所在节点
	void removeMax(){
		if(root){
			root = removeMax( root );
		}
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
	//在以node为根的二叉搜索树中,返回最小键值的节点	
	Node* minimum(Node* node){
		if(node->left == NULL){
			return node;
		}
		return minimum(node->left);
	}
	
	//在以node为根的二叉搜索树中,返回最大键值的节点
	Node* maximum(Node* node){
		if(node->right == NULL){
			return node;
		}
		return maximum(node->right);
	}
	
	//删除掉以node为根的二分搜索树中的最小节点
	//返回删除节点的新的二分搜索树的根
	Node* removeMin(Node* node){
		
		if(node->left == NULL){
			Node* right = node->right;
			delete node;
			count--;
			return rightNode;
		}
		
		node->left = removeMin(node->left);
		return node;
	}
	
	//删除掉以node为根的二分搜索树中的最大节点
	//返回删除节点后新的二分搜索树的根
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
};