// https://dmoj.ca/problem/coci13c1p4

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    
    vector<pair<int,int>> jewel;
    jewel.reserve(n);
    for(int i=0;i<n;i++){
        int a,b;    //2nt a->mass 1std b->value
        cin>>a>>b;
        jewel.push_back(make_pair(b,a));
    }
    
    multiset<int> bags;
    for(int i=0;i<k;i++){
        int a;
        cin>> a;
        bags.insert(a);
    }
    
    //  for (auto itr = bags.begin(); itr != bags.end(); ++itr) 
    // { 
    //     cout << '\t' << *itr; 
    // } 
    
    sort(jewel.begin(),jewel.end(),greater<pair<int,int>>());
    // for(int i=0;i<n;i++){
    //     cout<<jewel[i].second<<" "<<jewel[i].first<<endl;
    // }
    
    int ans =0;
    
    for(int i=0;i<n;i++){
        int mass = jewel[i].second;
        auto it = lower_bound(bags.begin(),bags.end(),mass);
        
        if(it != bags.end()){
            //cout<<*it<<endl;
            ans+= jewel[i].first;
            bags.erase(it);
        }
    }
    cout<<ans;
    
}