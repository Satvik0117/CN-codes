#include "binaryTree.cpp"

class BST{
	BinaryTreeNode<int>* root;

public:
	BST(){
		root=NULL;
	}
	~BST(){
		delete root; //has been made recursively in binaryTree.cpp
	}
private:
	bool hasNode(int data,BinaryTreeNode<int>* root){
		if(root==NULL)
			return false;
		if(root->data==data)
			return true;
		if(root->data> data)
			return hasNode(data,root->left);
		else
			return hasNode(data,root->right);


	}

	BinaryTreeNode<int>* insert(data,BinaryTreeNode<int>* root){
		if(root==NULL){
			BinaryTreeNode<int>* node = new BinaryTreeNode<int>*(data);
			return node;
		}
		if(root->data > data){
			root->left = insert(data,root->left);
			return root;
		}
		if(root->data <= data){
			root->right = insert(data,root->right);
			return root;
		}
	}

public:
	bool hasNode(int data){
		return hasNode(data,root);
	}

	void insert(int data){
		root=insert(data,root);
	}

}