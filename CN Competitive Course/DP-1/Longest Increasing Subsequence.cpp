#include<iostream>
using namespace std;

int findLIC(int* arr,int *ans_inc,int n){
    ans_inc[0] = 1;
    for(int i=1;i<n;i++){
        ans_inc[i] = 1;
        for(int j=i-1;j>=0;j--){
            //int op;
            if(arr[j] <= arr[i]){
                ans_inc[i] = max(ans_inc[i],ans_inc[j] +1);
            }
            
        }
    }
    int longest=ans_inc[0];
    for(int i=1;i<n;i++){
        if(ans_inc[i]>longest)longest=ans_inc[i];
    }
    return longest;
}


int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int ans_inc[n];
    cout<<findLIC(arr,ans_inc,n)<<endl;
    for(int i=0;i<n;i++) cout<<ans_inc[i]<<" ";
}