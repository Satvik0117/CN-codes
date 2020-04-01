#include <bits/stdc++.h>
using namespace std;


bool check(int stalls[], int distance, int numCows, int numStalls){
	int lastCowPos = 0;
	int cowCount=1;
	for(int i=1; i<numStalls;i++){
		if(stalls[i]-stalls[lastCowPos]>=distance){
			lastCowPos=i;
			cowCount++;
		}
		if(cowCount == numCows){
			return true;
		}
	}
	return false;
}


int main(){
	int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int numStalls,numCows;
        cin>>numStalls;
        cin>>numCows;
        int stalls[numStalls];

        for(int j=0;j<numStalls;j++){

            cin>>stalls[j];
        }
        sort(stalls,stalls+numStalls);

        int start=1;
        int end1 = stalls[numStalls-1]-stalls[0];		//start and end1 of distances possible
        int dist_ans=-1;
        while(start <= end1){
        	int mid = (start+end1)/2;
        		cout<<"mid: "<< mid<<"-->" <<check(stalls,mid,numCows,numStalls)<<endl;

        	if(check(stalls,mid,numCows,numStalls)){
        		dist_ans = mid;
        		start = mid+1;
        	}
        	else{
        		end1 = mid-1;
        	}

        }
        cout<<dist_ans<<endl;

	}
}
