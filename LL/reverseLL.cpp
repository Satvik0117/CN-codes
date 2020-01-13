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


Node* reverse(Node* h){
    if(h->next==NULL){
        return h;
    }
    Node* smallAns=reverse(h->next);
    Node* temp=smallAns;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=h;
    h->next=NULL;
    return smallAns;
}

int main(){
    Node*h=takeinput();
    //print(h);
    //reverse(h);
    print(reverse(h));

}
