#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,p;
        cin>>i>>p;
        int ans=0;
        for(int j=p;j>0;j--){
            i=i%11;
            i++;
        }
        cout<<i;
    }
}
