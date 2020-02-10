#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* right;
	Node* down;

	Node(int data){
		this->data = data;
		right = NULL;
		down = NULL;
	}
};
  
Node* flatten(Node* start){
	Node* output = new Node(start->data);
	Node* temp = output;
	Node* right = start->right;
	Node* down = start->down;

	while(right!= NULL && down!=NULL){
		if(right->data > down->data){
			Node* newNode = new Node(down->data);
			temp->right = newNode;
			down = down->down;
		}else{
			Node* newNode = new Node(down->data);
			temp->right = newNode;
			right = right->down;
		}
	}
}

int main(){



}