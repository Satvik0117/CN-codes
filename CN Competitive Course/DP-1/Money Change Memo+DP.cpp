#include<iostream>
using namespace std;



//Memoization
int coin_change(int money,int numCoin, int* d,int** output){
  //  cout<<money<<endl;
    
    if(money==0){   // 1 solution (no coin)
        return 1;
    }
    if(money<0) return 0;   //no Solution
    if(numCoin==0) return 0;        
    if(money>=1 && numCoin <=0) return 0;   //no Solution
    
    if(output[numCoin][money] != -1) return output[numCoin][money];
    
    int a = coin_change(money-d[0], numCoin,d ,output);   //coin will be in ans
    int b = coin_change(money,numCoin-1,d+1,output);               //coin will NOT be in ans
    
    output[numCoin][money] = a+b;
    
    return a+b;
    
}


int main(){
    int n;
    cin>>n;
    int d[n];
    for(int i=0;i<n;i++)cin>>d[i];
    int v;
    cin>>v;
    int** output = new int*[n];
    for(int i=0;i<v;i++){
        output[i] = new int[v];
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<v+1;j++){
            output[i][j] = -1;
        }
    }

   // cout<<coin_change(v,n)<<endl;
    cout<<coin_change(v,n,d,output)<<endl;
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<v+1;j++){
    //        cout<< output[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}