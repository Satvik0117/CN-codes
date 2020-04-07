#include<bits/stdc++.h>
#include<cmath>
using namespace std;


int knapsack(int wt[], int val[], int w, int i){
    if(w<=0 || i == 3){
        return 0;
    }
    
    if(wt[i] > w){
       return knapsack(wt,val,w,i+1);
    }
    
    // int op1 = knapsack(wt,val,w-wt[i],i+1)+val[i];
    // int op2 = knapsack(wt,val,w,i+1);
    // if(op1>=op2){
    //     return val[i]+ knapsack(wt,val,w-wt[i],i+1); 
    // }
    // return knapsack(wt,val,w,i+1);
    return (val[i]+knapsack(wt,val,w-wt[i],i+1) , knapsack(wt,val,w,i+1));;
}


int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};  
    int W = 50;  
    int n=3;
    cout<<knapsack(wt,val,W,0);
    
}