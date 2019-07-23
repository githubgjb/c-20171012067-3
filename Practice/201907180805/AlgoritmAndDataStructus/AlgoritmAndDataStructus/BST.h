#include <iostream>
using namespace std;

template <template Key,typename Value>
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
			this->left = this->right = NULL:
		}
	};

	Node *root;
	int count;
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
