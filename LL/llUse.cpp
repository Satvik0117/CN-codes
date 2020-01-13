#include <iostream>
using namespace std;

#include "ll.cpp"


Node* takeinput(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* tail=NULL;
    //cout<<"asd";
    while(data!=-1){
        Node *n1=new Node(data);
        if(head==NULL){
            head=n1;
            tail=n1;
        }
        else{
        //     Node* temp=head;
        //     while(temp->next!=NULL){
        //         temp=temp->next;
        //     } //after this loop we reach the last node or the temp points to the last node
        // temp->next=n1;
        // complexity of abve is O(n^2)
        //  BETTER
        tail->next=n1;
        tail=n1; // or tail=tail->next;
        // complexity O(n)
        }
        cin>>data;
    }
return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        //cout<<"a";
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insert(Node* head,int index,int data){
    Node* temp=head;
    if(index==0){
        Node *newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }

    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    //cout<<temp->data;
    Node* temp2=temp->next;
    Node *newNode=new Node(data);
    temp->next=newNode;
    newNode->next=temp2;
    return head;

}
Node* deleteNode(Node* head,int index){
    Node*temp=head;
    if(index==0){
        head=head->next;
        return head;
    }
    for(int i=0;i<index-1;i++){
        temp=temp->next;

    }
    Node* a=temp->next;
    Node* b=a->next;
    delete a;
    temp->next=b;

    return head;

}
int lengthRecursive(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1+lengthRecursive(head->next);
}

Node* insertRecursive(Node* head, int index, int data){
    if(index==0){
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        return head;
    }
         Node*x=insertRecursive(head->next,index-1,data);
         head->next=x;
}
Node* deleteRec(Node* head,int index){
    if(index==0){
        return head->next;
    }
    Node*x=deleteRec(head->next,index-1);
    head->next=x;

}

void midPoint(Node* head){
    Node* slow=head;
    //cout<<slow->data;
    Node* fast=head->next;
    //cout<<"a";
    while(fast->next!=NULL && fast!=NULL){ //1 bhi null hote hi stop the loop
        slow=slow->next;
        fast=fast->next->next;
       // cout << slow->data;
       // cout<<"moving";
    }
    cout<<"sdafsgd";
    cout<< "Mid Point"<<slow->data;
}

Node* merge(Node* h1,Node* h2){
    int l1=lengthRecursive(h1);
    int l2=lengthRecursive(h2);
    Node* fh;
    Node* tail;
    if( h1->data < h2->data){
            fh=h1;
            tail=h1;
            h1=h1->next;
    }
    else{
            fh=h2;
            tail=h2;
            h2=h2->next;
    }
    while(h1!=NULL && h2!=NULL){
        if( h1->data < h2->data){
            tail->next=h1;
            tail=h1;
            h1= h1->next;
        }
        else{
            tail->next=h2;
            tail=h2;
            h2= h2->next;
        }
    }
    if(h1==NULL){
        tail->next=h2;
    }
    else if(h2==NULL)
        tail->next=h1;

return fh;
}
Node* mergeSort(Node* h,int si,int ei){
if(si-ei==0){
    return h;
}
int mid=(si+ei)/2;

Node* h1=mergeSort(h,si,mid);
Node* h2=mergeSort(h,mid+1,ei);
Node* finalh=merge(h1,h2);
return finalh;
}


int main(){
    // Node n1(2);
    // cout <<&n1;
    //Node* head = takeinput();
    //print(head);
    //int i,data;
    //cin>>i;
   // head=deleteNode(head,i);
    //cout<< lengthRecursive(head);
    //print(head);
   // head=deleteRec(head,5);
    //print(head);
    //midPoint(head);
   // cout<< "Mid Point: " << mid->data;
/*
    Node*h1=takeinput();

    Node*h2=takeinput();
    print(h1);
    cout<<endl;
    print(h2);
    cout<<endl;
   Node* h= merge(h1,h2);
    print(h1);
    print(h2);
    print(h);*/
    Node* h1 =takeinput();
    int si=0,ei=4;
    print(mergeSort(h1,si,ei));

}
