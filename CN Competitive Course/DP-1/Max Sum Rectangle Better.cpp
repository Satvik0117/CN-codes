#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
     int maxi = arr[0];
    int prv;
    prv = arr[0];
    for(int i=1;i<n;i++){
        if(prv > 0){
            prv = prv+arr[i];
        }else{
            prv = arr[i];
        }
    maxi = max(prv,maxi);
    }

    return maxi;
}

int findMaxSum(int** input,int n,int m){
    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        int arr[n]={}; 
        for(int j=i;j<m;j++){
            
                for(int k=0;k<n;k++){
                    arr[k] += input[k][j];      //NOTE we are updating the array with new elements at every right selected thus not finding sum for all everytime
                }
                ans = max(kadane(arr,n),ans);
        }
    }
    return ans;
}


int main(){
 int n,m;
    cin>>n>>m;
    int** input = new int*[n];
    for(int i=0;i<m;i++){
        input[i] = new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }
    cout<<findMaxSum(input,n,m);

}