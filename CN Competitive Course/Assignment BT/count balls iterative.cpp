#include<bits/stdc++.h>
using namespace std;
long long main()
{
    long long n;
    cin>>n;
    long long left = 1;
    long long right = n;
    long long ans;
    while(left<=right){
        
        long long k = left + (right-left)/2;
        long long temp =n;
        long long ballA=0;    //sharma
        long long ballB=0;    //singh
        while(temp>0){
            if(temp<k){
                ballA+=temp;
                temp=0;
            }else{
                temp -= k;
                ballA+=k;
                ballB+=temp/10;
                temp -= temp/10;
            }
        }
        if(2*ballA>=n){
            ans = k;
            right=k-1;    
        }else{
            left = k+1;
        }
        
    }
    cout<<ans;
    
    
   
	return 0;
}
