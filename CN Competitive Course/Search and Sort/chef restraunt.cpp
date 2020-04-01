#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(const pair<int,int> p1,const pair<int,int> p2){
    return p1.first < p2.first;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int numInt,numPeople;
	    cin>>numInt>>numPeople;
	    vector<pair<int,int>> intervals;
	    intervals.reserve(numInt);
	    for(int i=0;i<numInt;i++){
	        int a,b;
	        cin>>a>>b;
	        pair<int,int> p;
	        p.first=a;
	        p.second = b;
	        intervals.push_back(p);
	    }
	    sort(intervals.begin(),intervals.begin()+numInt,compare);
	    while(numPeople--){
	    	int curr_time;
	    	cin>>curr_time;
		        int x =lower_bound(intervals.begin(),intervals.end(),make_pair(curr_time,0))-intervals.begin();
		        if(x==0){
		            cout<<intervals[0].first - curr_time<<endl;
		        }else{
		        	int ans = -1;
		        	if(intervals[x-1].second>curr_time){
		        		ans=0;
		        	}else if(x < intervals.size()){
		        		ans= intervals[x].first - curr_time;
		        	}
		        	cout<<ans<<endl;
		        }


		        // else if(x==0){
		        //     cout<<intervals[0].first - curr_time<<endl;
		        // }
		        // else if(intervals[x].first == curr_time){
		        //     cout<<0<<endl;
	         //    }
		        // else if(intervals[x-1].second > curr_time ){
		        //     cout<<0<<endl;
		        // }
		        // else if(intervals[x-1].second == curr_time){
		        // 	cout<<intervals[x].first -curr_time<<endl;
		        // }



		}


	return 0;
}}
