#include<bits/stdc++.h>
using namespace std;

bool check(int a[],int currCandy,int numStu,int n){
    int count=0;
    for(int i=0;i<n;i++){
        count += a[i]/currCandy;
    }
    return (count>=numStu);
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;        //k->num students     n->num boxes
        cin>>n>>k;
        int a[n];       
        for(int i=0;i<n;i++){
            cin>>a[i];  //a[i]-> num of candies in ith box
        }
        
        sort(a,a+n);
        
        int max_candies = a[n-1];
        int min_candies=0;
        int left=0,right=max_candies;
        int ans=0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(a,mid,k,n)){
                ans=mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        cout<<ans<<endl;
        
        
        
    }
}