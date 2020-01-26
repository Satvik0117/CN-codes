#include <iostream>
#include "binaryTree.cpp"
#include <queue>
#include <typeinfo>
//#include "ll.cpp"
//#include "F:\Courses\C++ DS CN\Programs\LL\llUse.cpp"

using namespace std;
//had to copy paste code because of some redefination error
class Node{
public:
    Node* next;
    int data;

Node(int data){
    this->data=data;
    next=NULL;
}
};
//print for LL
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        //cout<<"a";
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

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

int maximum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MIN; 	// NOTE MIN
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL)
        return INT_MAX;  //NOTE MAX
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}


bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL)
        return true;
    int leftMax= maximum(root->left);
    int rightMin = minimum(root->right);
    bool output= leftMax < root->data && rightMin >= root->data && isBST(root->left) && isBST(root->right);
    return output;
}

class isBSTreturn{
public:
	bool isBST;
	int maximum;
	int minimum;
};

isBSTreturn isBST2(BinaryTreeNode<int>* root){
	if(root==NULL){
		isBSTreturn output;
		output.isBST=true;
		output.minimum=INT_MAX;
		output.maximum=INT_MIN;
		return output;
	}

	isBSTreturn leftOutput = isBST2(root->left);
	isBSTreturn rightOutput = isBST2(root->right);
	int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
	int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
	bool isBSTFinal = leftOutput.maximum < root->data && rightOutput.minimum >=root->data && rightOutput.isBST && leftOutput.isBST;
	isBSTreturn output;
	output.maximum=maximum;
	output.minimum=minimum;
	output.isBST =isBSTFinal;
	return output;

}

bool isBST3(BinaryTreeNode<int>* root, int min=INT_MIN, int max= INT_MAX){
    if(root==NULL)
        return true;
    if(root->data < min || root->data > max)
        return false;
    bool isLeftok = isBST3(root->left,min,root->data-1);
    bool isRightok = isBST3(root->right,root->data, max);
    return isLeftok && isRightok;
}

BinaryTreeNode<int>* BSTfromArr(int arr[],int si, int ei){
    if(si>ei)
        return NULL;
    int mid = (si+ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int>* left = BSTfromArr(arr,si,mid-1);
    BinaryTreeNode<int>* right = BSTfromArr(arr,mid+1,ei);
    root->left = left;
    root->right = right;
    return root;
}

pair<Node*,Node*> LLfromBST(BinaryTreeNode<int>* root){
    if(root==NULL){
        //cout<<"null";
        pair<Node* , Node*> p;
        p.first=NULL;
        p.second=NULL;
        return p;
    }
    Node* node = new Node(root->data);
    pair<Node* , Node*> leftLL = LLfromBST(root->left);
    pair<Node* , Node*> rightLL = LLfromBST(root->right);
    pair<Node*,Node*> ans;
    if(leftLL.first==NULL){
        ans.first=node;
        ans.second=node;
    }
    else{
        leftLL.second->next=node; //make the last element of left LL point to node created %
        ans.first=leftLL.first; // store head in ans
        ans.second=rightLL.second; 	// store tail of right ll in ans.second
    }
    node->next=rightLL.first; // connect node with head of right LL #

    return ans;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root==NULL)
        return NULL;
    if(root->data==data){
        vector<int>* output = new vector<int>;
        output->push_back(data);
        return output;
    }
    vector<int>* leftOutput=getRootToNodePath(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput=getRootToNodePath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    //if not in left not in right
    else{
    return NULL;
    }



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
//BT 1 2 3  4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// Binary SEARCH Tree:-
    int arr[]={1,2,3,4,5,6,7};
    int length=sizeof(arr)/sizeof(arr[0]);
    //cout<<length<<endl;
    BinaryTreeNode<int>* root=takeInputLevelwise();
   // printTree(root);
    //BSTprintWithinRange(root, 1,7);
    //BinaryTreeNode<int>* result =bstSearch(root,3);
    //cout<<"SEARCH RESULT : "<<result->data;
    // cout<<isBST2(root).isBST<<endl;
     //cout<<isBST3(root)<<endl;
    //cout<<minimum(root);
    //cout<<maximum(root);
    //printTree(BSTfromArr(arr,0,length-1));
    //BinaryTreeNode<int>* root =BSTfromArr(arr,0,length-1);
    printTree(root);
//    delete root;
    //print(LLfromBST(root).first);
    vector<int>* path = getRootToNodePath(root,8);
    for(int i=0;i<path->size();i++){
        cout<<path->at(i)<<"->";
    }
    delete path;
}
