#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
                
        for(int i=0;i<n;i++){
            if(arr[i+1] == arr[i]-1){
                swap(arr[i+1],arr[i]);
            }
        }
        string ans="Yes";
        for(int i=0;i<n-1;i++){
            if(arr[i+1]<arr[i])
                ans="No";
        }
        
        cout<<ans<<endl;
        
    }
    
}