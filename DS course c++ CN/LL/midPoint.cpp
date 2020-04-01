#include <iostream>
using namespace std;

#include "ll.cpp"

Node* midPoint(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast->next!=NULL || fast==NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}



int main(){


}
