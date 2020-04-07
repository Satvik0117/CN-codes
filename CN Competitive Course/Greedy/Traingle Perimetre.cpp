#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int k=0;
    int i=n-1;
    for(;i>=2;i--){
        if(arr[i]<arr[i-1]+arr[i-2]){
            k=1;

           break; 
        }
    }
    if(k==1){
        cout<<arr[i-2]<<" "<<arr[i-1]<<" "<<arr[i];
    }
    if(k==0){
        cout<<-1;
    }
    return 0;
}
