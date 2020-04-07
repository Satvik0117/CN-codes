#include<bits/stdc++.h>
using namespace std;

bool isPossible(int input[][20],int ans[][20],int n,int row,int col){
    if(row<n && col<n && row>=0 && col >=0 && input[row][col] !=0 && ans[row][col]!=1){
        return true;
    }
    return false;
}

void ratHelper(int input[][20],int ans[][20],int n, int row,int col){
    if(row==n-1 && col ==n-1){
        ans[n-1][n-1]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cout<< ans[i][j]<<" ";
            }
        }
        cout<<endl;
        ans[n-1][n-1]=0; //doesn't really matter

        return;
    }
    
    if(isPossible(input,ans,n,row,col)){
        ans[row][col]=1;
        ratHelper(input,ans,n,row-1,col);  //up
        ratHelper(input,ans,n,row+1,col);  //down
        ratHelper(input,ans,n,row,col-1);  //left
        ratHelper(input,ans,n,row,col+1);  //right
        ans[row][col]=0;
        
    }
    return;
    
    
}


void ratInAMaze(int maze[][20],int n){
    int ans[20][20]; 
    memset(ans,0,sizeof(int)*20*20);
    ratHelper(maze,ans,n,0,0);
}
