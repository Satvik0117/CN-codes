#include<bits/stdc++.h>
using namespace std;

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
        int min_candies = a[0];
        int ans=0;
        for(int i=1;i<=max_candies;i++){ 
            int temp[n];
            for(int j=0;j<n;j++){
                temp[j]=a[j];
            }
            int x=0,numStu=k;
            while(numStu!=0 && x<n){
                if(temp[x]>=i){
                    temp[x] -= i;
                    numStu--;
                }else{
                    x++;
                }
            }
            if(numStu==0)
                ans=i;

        }
        cout<<ans<<endl;
        
        
        
    }
}