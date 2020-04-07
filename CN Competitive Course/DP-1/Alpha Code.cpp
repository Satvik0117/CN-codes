#include <iostream>
using namespace std;


int main(){
    while(1){
    string s;
    cin>>s;
    if(s=="0") break;
    
    int n=s.length();
    int ans[n];
    ans[0]=1;
    ans[1]=1;
    if((s[0]-'0')*10 + (s[1]-'0')<=26)
        ans[1] = 2;
    
    for(int i=2;i<n;i++){
        // ans+=1;
        ans[i]= ans[i-1];
        // cout<<(s[i-1]-'0')*10 + (s[i]-'0')<<endl ;
        if((s[i-1]-'0')*10 + (s[i]-'0')<=26){
            
            ans[i] += ans[i-2] ;
        }
    }
    cout<<ans[n-1]<<endl;
    
    }
}