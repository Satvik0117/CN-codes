#include <bits/stdc++.h>
#define M 1000
#define N 1000
using namespace std;

int grid(int input[M][N],int sr,int sc,int er,int ec,int output[M][N]){
    if(sr == er && sc ==ec){
        return 1;
    }
    if(sr>er || sc>ec){
        return INT_MAX;
    }
    int op1 = grid(input,sr,sc+1,er,ec,output) ;
    int op2 = grid(input,sr+1,sc,er,ec,output) ;
    int a = min(op1,op2) -  input[sr][sc];
    //cout<<sr<<"," <<sc<<"->" <<op1<<" " <<op2<<endl;
	if(a<=0) a=1;
    output[sr][sc] = a;
    //cout<<sr<<"," <<sc<<"->" <<a<<endl;
    return output[sr][sc];
}

int gridDP(int input[M][N],int sr,int sc,int er,int ec,int output[M][N]){
    output[er][ec] = 1;
    for(int i=ec-1;i>=0;i--){
        output[er][i] = max(output[er][i+1]-input[er][i],1);
    }
    for(int i=er-1;i>=0;i--){
        output[i][ec] = max(output[i+1][ec]-input[i][ec],1);
    }
    for(int i=er-1;i>=0;i--){
        for(int j=ec-1;j>=0;j--){
            output[i][j] = max(min(output[i+1][j],output[i][j+1]) - input[i][j],1);
        }
    }
    return output[0][0];
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int m,n;
        cin>>m>>n;
          int input[M][N];
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                cin>>input[i][j];
             
        int output[M][N];
        for(int i = 0;i<M;i++)
            for(int j = 0;j<N;j++)
                output[i][j] = -1;
        //cout<<grid(input,0,0,m-1,n-1,output)<<endl;
        cout<<gridDP(input,0,0,m-1,n-1,output)<<endl;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<< output[i][j]<<" ";
    //     }
    //     cout<<endl;
    //  }
}
    return 0;
}
