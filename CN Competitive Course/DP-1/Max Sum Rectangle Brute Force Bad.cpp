#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int** input,int n,int m){
    int sum[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int sum1=0;
            for(int k=i;k<n;k++){
                for(int l=j;l<m;l++){
                    sum1+= input[k][l];
                }
            }
            sum[i][j] = sum1;
        }
    }

    int ans= INT_MIN ;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            for(int k=i;k<n;k++){
                for(int l=j;l<m;l++){
                    if(k==n-1 && l==m-1){
                        ans = max(ans,sum[i][j]);
                    }
                    else if(k==n-1){
                    ans = max(ans,sum[i][j] -sum[i][l+1]);
                    }
                    else if(l==m-1){
                    ans = max(ans,sum[i][j]- sum[k+1][j] ); 
                    }
                    else ans = max(ans,sum[i][j] -sum[i][l+1] - sum[k+1][j] + sum[k+1][l+1]);
                }
            }
            
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