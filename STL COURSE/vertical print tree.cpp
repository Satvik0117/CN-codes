#include <iostream>
#include <map>
#include <vector>
using namespace std;


template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
   /* BinaryTreeNode(){
    left=NULL;
    right=NULL;
        }
*/
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

void getVerticalOrder(BinaryTreeNode<int>* root,int d , map<int,vector<int>> &m){
    if(root == NULL)
        return;
    m[d].push_back(root->data);
    getVerticalOrder(root->left, d-1, m);
    getVerticalOrder(root->right, d+1, m);
    return;

}


int main(){

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);

    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    root->right->right->right = new BinaryTreeNode<int>(9);
    root->left->right->right = new BinaryTreeNode<int>(8);


    map<int,vector<int>> m;
    int d =0;
    getVerticalOrder(root,d ,m);

    for(auto p : m){
        cout<<"for distance"<<p.first<<"->";
        for(auto data : p.second){
            cout<<data<<",";
        }
        cout<<endl;
    }

}
