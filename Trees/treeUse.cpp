#include <iostream>
#include <vector>
#include <queue>
#include "tree.cpp"
using namespace std;

void printTree(TreeNode<int>* root){
    //this is not a base case, we can call it an edge case
    if(root==NULL)
        return;
    //BASE CASE NOT REQUIRED HERE
    cout<<root->data<<":";
    for(int i=0;i<root->treeChildren.size();i++){
       cout<<root->treeChildren.at(i)->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->treeChildren.size();i++){
        printTree(root->treeChildren.at(i));
    }
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root data"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the number of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            cout<<"Enter the "<<i<<"th child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>* childNode=new TreeNode<int>(childData);
            front->treeChildren.push_back(childNode);
            pendingNodes.push(childNode);

        }
    }
    return root;
}

int main(){
    //using static memory allocation
    /* TreeNode<int> root2;
    TreeNode<int> child3;
    TreeNode<int> child4;
    root2.data=3;
    child3.data=4;
    child4.data=5;
    root2.treeChildren.push_back(&child3);
    root2.treeChildren.push_back(&child4);
    printTree(&root2);*/

  /*  //using dynamic mem all
    TreeNode<int>* root =new TreeNode<int>;
    TreeNode<int>* child1 =new TreeNode<int>;
    TreeNode<int>* child2 =new TreeNode<int>;
    root->data=1;


   // TreeNode<int>* child3 =new TreeNode<int>(4);
    root->treeChildren.push_back(child1);
    root->treeChildren.push_back(child2);
   // root->treeChildren.push_back(child3);
    child1->data=2;
    child2->data=3;
    */
    TreeNode<int>* root=takeInputLevelWise();
    printTree(root);


}
