#include<bits/stdc++.h>
using namespace std;

class Job{
 public:
    int start;
    int finish;
    int profit;
};


bool compare(Job j1,Job j2){
    return j1.finish < j2.finish;
}

int binarySearch(Job arr[], int currJob){
    int left = 0;
    int right = currJob-1;
    int ans=-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid].finish <= arr[currJob].start){
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    
    sort(arr,arr+n,compare);
   // My Own
    // vector<pair<int,int>> v;
    // v.reserve(n);
    // v.push_back(make_pair(arr[0].profit,0));
    // for(int i=1;i<n;i++){
    //     v.push_back(make_pair(0,0));
    //     v[i].second = max(v[i-1].first,v[i-1].second);
    //     for(int j=i-1;j>=0;j--){
    //         v[i].first = arr[i].profit;
    //         if(arr[j].finish <= arr[i].start){
    //             v[i].first  = max(v[j].first,v[j].second)+arr[i].profit;
    //             // v[i].second = max(v[j].first,v[j].second);
    //             break;
    //         }
    //     }
        
   
    // }
    // cout<< max(v[n-1].first,v[n-1].second);
    // Didn't need to have a vector of pairs, Can simply store the maximum answer in an array

    // Lets implement using the binary search instead of inner for loop 
    int ans[n];
    ans[0] = arr[0].profit;
    for(int i=1;i<n;i++){
        int index = binarySearch(arr,i);
        int including = arr[i].profit; //if no feasible job is found
       // cout<<index<<endl;
        if(index!=-1){
            including =ans[index]+including;
        }
        ans[i] = max(including, ans[i-1]);
    }
    
    cout<<ans[n-1];
    
    
}