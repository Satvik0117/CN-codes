#include<bits/stdc++.h>
using namespace std;

int getSubseq(string input, string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    
    string smallString = input.substr(1);
    int smallOutputSize = getSubseq(smallString, output);
    for(int i=0;i<smallOutputSize;i++){
        output[i+smallOutputSize] = input[0] + output[i];
    }
    return 2*smallOutputSize;
    
}



int main(){
     string s;
     getline(cin,s);
     //cout<<pow(2,s.length());
     string arr[(int)pow(2,s.length())];
     int n = getSubseq(s,arr);
     for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
     
     
}