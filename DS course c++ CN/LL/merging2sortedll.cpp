#include <iostream>
using namespace std;

#include "ll.cpp"

#include "llUse.cpp"

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



int main(){

    Node*h1=takeinput();

    Node*h2=takeinput();
   Node* h= merge(h1,h2);
    print(h1);
    cout<<endl;
    print(h2);
    cout<<endl;
    print(h);

}
