#include<bits/stdc++.h>
using namespace std;

long long check(long long n,long long k,long long sharma,long long singh){
    long long f=0,m;    
    m=n;
    while(m>0){
        if(m<k){
            sharma=sharma+m;
            m=0;
            f=1;
        }
        if(f) break;
        sharma=sharma+k;
        m=m-k;
        singh=singh+(m/10);
        m=m-(m/10);   
    }
    if(2*sharma>=n) return 1;
    else return 0;
}

long long binary_search(long long n,long long start,long long end,long long sharma,long long singh){
    if(start>end) return start;
    long long mid=(start+end)/2;
    if(check(n,mid,sharma,singh)) end=mid-1;
    else start=mid+1;
    binary_search(n,start,end,sharma,singh);
}

int main()
{
    long long n,sharma=0,singh=0;
    cin>>n;
    cout<<binary_search(n,1,n-1,sharma,singh);
	return 0;
}
