#include <iostream>
using namespace std;

#include "stacks_using_ll.cpp"
#include <stack>
int main(){
    stack<char> s; // inbuilt stack note the 1st letter is small, we made it to be capital in our class
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;

    s.pop();

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    //cout<<s.top()<<endl;
   // s.pop();
    //cout<<s.top()<<endl;
    //s.pop();
    //cout<<s.top()<<endl<<s.isEmpty();
    //s.pop();
    //cout<<s.top()<<endl<<s.isEmpty();
}
