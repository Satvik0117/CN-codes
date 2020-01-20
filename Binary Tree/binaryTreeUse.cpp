#include <iostream>
#include "binaryTree.cpp"
#include <queue>

using namespace std;

void printTree(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
    cout<< root->data << ":";
    if(root->left!=NULL)
        cout<<"L" <<root->left->data<<",";
    if(root->right!=NULL)
        cout<<"R"<< root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){

    int rootData;
    cout<< "Enter Root Data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* left=takeInput();
    BinaryTreeNode<int>* right=takeInput();
    root->left=left;
    root->right=right;
    return root;
}

BinaryTreeNode<int>* takeInputLevelwise(){
    cout<<"Enter root data"<<endl;
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the Left Node Data of "<< front->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            BinaryTreeNode<int>* leftNode=new BinaryTreeNode<int>(leftData);
            //leftNode->data=leftData;
            front->left=leftNode;
            pendingNodes.push(leftNode);
        }
        cout<<"Enter the Right Node Data of "<< front->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            BinaryTreeNode<int>* rightNode=new BinaryTreeNode<int>(rightData);
           // rightNode->data=rightData;
            front->right=rightNode;
            pendingNodes.push(rightNode);
        }


    }
    return root;

}

int numNode(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    return 1+numNode(root->left)+numNode(root->right);


}

void inorder(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre,int inS, int inE, int preS, int preE){
    if(inS>inE)
        return NULL;
    int rootData=pre[preS];
    int inRootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            inRootIndex=i;
            break;
        }
    }
    int lInS=inS;
    int lInE=inRootIndex-1;
    int rInS=inRootIndex+1;
    int rInE=inE;
    int lPreS=preS+1;
    int lPreE=lPreS-lInS+lInE;
    int rPreS=lPreE+1;
    int rPreE=preE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left=buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right=buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int>* buildTree(int* in,int* pre,int size){
    return buildTreeHelper(in, pre, 0, size-1, 0, size-1);

}

int height(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    return 1 + max(height(root->left),height(root->right));
}

int diametre(BinaryTreeNode<int>* root){
    if(root==NULL)
        return 0;
    int option1 = height(root);
    int option2 = diametre(root->left);
    int option3 = diametre(root->right);
    return max(option1,max(option2,option3));
}

pair<int,int> diametreHeight(BinaryTreeNode<int>* root){

    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns=diametreHeight(root->left);
    pair<int,int> rightAns=diametreHeight(root->right);
    int ld=leftAns.second,lh=leftAns.first,rd=rightAns.second,rh=rightAns.first;
    int height=1+max(lh,rh);
    int diametre=max(lh+rh,max(rd,ld));
    pair<int,int> p;
    p.first=height;
    p.second=diametre;
    return p;
}

BinaryTreeNode<int>* bstSearch(BinaryTreeNode<int>* root,int data){
    //cout<<data;
    if(root==NULL)
        return NULL;
    if(root->data<data){
        //search right
        return bstSearch(root->right,data);
    }
     else if(root->data>data){
        //search left
        return bstSearch(root->left,data);
    }
    else if(root->data==data){
        return root;
    }

}

void BSTprintWithinRange(BinaryTreeNode<int>* root, int RangeMin, int RangeMax){
    //Better solution on gfg

    if(root==NULL)
        return;
    if(root->data< RangeMax && root->data > RangeMin)
        cout<<root->data <<endl;
    if(root->data < RangeMin)
        BSTprintWithinRange(root->right,RangeMin,RangeMax);
    else if(root->data > RangeMax)
        BSTprintWithinRange(root->left,RangeMin,RangeMax);
    else
        BSTprintWithinRange(root->left,RangeMin,RangeMax);
        BSTprintWithinRange(root->right,RangeMin,RangeMax);
}

int main(){
   /* BinaryTreeNode<int>* root= new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1= new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2= new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;
    */

    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};

  //  BinaryTreeNode<int>* root = buildTree(in, pre, 9);
// Binary SEARCH Tree:- 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root=takeInputLevelwise();
    printTree(root);
    BSTprintWithinRange(root, 1,7);
    //BinaryTreeNode<int>* result =bstSearch(root,3);
    //cout<<"SEARCH RESULT : "<<result->data;

    delete root;
}
