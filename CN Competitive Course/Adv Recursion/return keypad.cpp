#include<iostream>
#include<string>
using namespace std;

string check(int num){
    string s;
    switch(num){
        case 0:
            s="";
            break;
        case 1:
            s="";
            break;
        case 2:
            s="abc";
            break;
        case 3:
            s="def";
            break;
        case 4: 
            s="ghi";
            break;
        case 5:
            s="jkl";
            break;
        case 6: 
            s="mno";
            break;
        case 7:
            s="pqrs";
            break;
        case 8:
            s="tuv";
            break;
        case 9:
            s="wxyz";
            break;
    }
    return s;
}

int returnKeypad(int n,string output[]){
    if(n==0 || n== 1){
        output[0]="";
        return 1;
    }
    string s = check(n%10);
    int smallOutput = returnKeypad(n/10,output);

    for(int j=1;j<s.length();j++){
        for(int i=0;i<smallOutput;i++){
            output[i+j*smallOutput]=output[i] + s[j];
        }
    }

    for(int i=0;i<smallOutput;i++){
        output[i] += s[0];
    }
    return s.length()*smallOutput;

}


int main(){
    int n;
    cin>>n;
    int temp=n;
    string output[100];
    
    int len = returnKeypad(n,output);
    
    
    while(temp>=10){
        cout<<temp%10<<endl;
        temp=temp/10;
        
    }
    cout<<temp;
    
    
}