#include <iostream>
#include <cstring>
using namespace std;

#include <stack>

bool checkBrackets(char s[]){
    return true;

}

int main(){

    stack<char> s;
    char sa[]="{a+[b-(c*d)]+g}";
    for(int i=0;i<strlen(sa);i++){
        if(sa[i]=='{' || sa[i]=='[' || sa[i]=='('){
            s.push(sa[i]);
           }
       }
       //cout<<s.top();
       //s.pop();
       //cout<<s.top();

    bool ans=true;
    for(int i=0;i<strlen(sa);i++){
        /*if(sa[i]=='}' || sa[i]==']' || sa[i]==')'){

            if(s.top()==sa[i]){
                s.pop();
            }
            else
                ans=false;

        }*/
        if(sa[i]=='}'){
            if(s.top()=='{'){
                s.pop();
            }
            else
                ans=false;
        }
        if(sa[i]==')'){
            if(s.top()=='('){
                s.pop();
            }
            else
                ans=false;
        }
        if(sa[i]==']'){
            if(s.top()=='['){
                s.pop();
            }
            else
                ans=false;
        }




    }

    cout<<ans;

}
