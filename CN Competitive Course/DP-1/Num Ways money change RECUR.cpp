#include<iostream>
using namespace std;

int d[11]{};
int x;


// could have passed d to the function too and updated money using that...d would be used only for updating money
// see GFG sol https://www.geeksforgeeks.org/coin-change-dp-7/
// GFG did by excluding least element of coin array, they decrease num coin and exclude d[numCoin-1]

//without d as argument
// BASE CASE ME LAFDA SEE GFG SOLUTION
int coin_change(int money,int numCoin){
  //  cout<<money<<endl;
    if(money==0){   // 1 solution (no coin)
        return 1;
    }
    if(money<0) return 0;   //no Solution
    if(numCoin==0) return 0;        
    if(money>=1 && numCoin <=0) return 0;   //no Solution

    int a = coin_change(money-d[x-numCoin], numCoin);   //coin will be in ans
    int b = coin_change(money,numCoin-1);               //coin will NOT be in ans

    return a+b;
    
}

// with d as arg
//d beign an arg doesn't make the function dependent on it, while doing MEMOIZATION we just need money and numCoin
int coin_change(int money,int numCoin, int* d){
  //  cout<<money<<endl;
    if(money==0){   // 1 solution (no coin)
        return 1;
    }
    if(money<0) return 0;   //no Solution
    if(numCoin==0) return 0;        
    if(money>=1 && numCoin <=0) return 0;   //no Solution

    int a = coin_change(money-d[0], numCoin, d);   //1st coin pointed by d will be in ans
    int b = coin_change(money,numCoin-1,d+1);      //coin will NOT be in ans => d+1 d will point to next coin

    return a+b;
    
}


int main(){
    int n;
    cin>>n;
    x=n;
    for(int i=0;i<n;i++)cin>>d[i];
    int v;
    cin>>v;
    int** output = new int[][];

    cout<<coin_change(v,n)<<endl;
    cout<<coin_change(v,n,d);

}