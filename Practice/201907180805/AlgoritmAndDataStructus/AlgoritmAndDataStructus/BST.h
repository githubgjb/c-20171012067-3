#include <iostream>
using namespace std;

template <typename Key, typename Value>
class BST{
private:
	struct Node
	{
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

	Node *root;
	int count;
public:
	BST(){
		root = NULL;
		count = 0;
	}
	~BST(){
		//TODO
		destory(root);
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

	Value* search(Key key){
		return search(root ,key);
	}

	void preOrder(){
		preOrder(root);
	}

	void inOrder(){
		inOrder(root);
	}

	void postOrder(){
		postOrder(root);
	}
private:
	Node* insert(Node *node,Key key,Value value){
		
		if (node == NULL)
		{
			count++;
			return new Node(key, value);
		}

		if (key == node->key)
		{
			node->value = value;
		}
		else if (key < node->key){
			node->left = insert(node->left, key, value);
		}
		else { // key > node->key
			node->right = insert(node->right,key,value);
		}

		return node;
	
	}

	bool contain(Node* node,Key key){
		if (node == NULL)
		{
			return false;
		}

		if (key == node->key)
		{
			return true;
		}
		else if (key < node->key){
			return contain(node->left,key);
		}
		else{ //key > node->key
			return contain(node->right, key);
		}
	}
	Value* search(Node* node , Key key){

		if (node == NULL)
		{
			return NULL;
		}

		if (key == node->key)
		{
			return &(node->value);
		}
		else if (key < node->key){
			return search(node->left, key);
		}
		else{ //key > node->key
			return search(node->right, key);
		}
	
	}

	void preOrder(Node* node){
		
		if (node != null)
		{
			cout << node->key << end;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void inOrder(Node* node){
		
		if (node!= null)
		{
			inOrder(node->left);
			cout << node->key << end;
			inOrder(node->right);
		}
	}
	void postOrder(Node* node){
		if (node != null)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << end;
		}
	}

	void destory(Node* node){
		if (node != NULL)
		{
			destory(node->left);
			destory(node->right);

			delete node;
			count--;
		}
	}
};
