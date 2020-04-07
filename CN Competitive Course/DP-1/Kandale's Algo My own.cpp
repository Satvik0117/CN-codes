#include<iostream>
using namespace std;

int maxSubArraySum(int arr[], int n){
    int maxi = arr[0];
    int lastIndex;
    int ans[n];
    ans[0] = arr[0];
    for(int i=1;i<n;i++){
        if(ans[i-1] > 0){
            ans[i] = ans[i-1]+arr[i];
        }else{
            ans[i] = arr[i];
        }

    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
        maxi = max(maxi,ans[i]);}
        cout<<endl;
    return maxi;
}

int main(){
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n= sizeof(arr)/sizeof(int);
    cout<<maxSubArraySum(arr,n);

}


// OR
#include<iostream>
using namespace std;

int maxSubArraySum(int arr[], int n){
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

int main(){
    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n= sizeof(arr)/sizeof(int);
    cout<<maxSubArraySum(arr,n);

}