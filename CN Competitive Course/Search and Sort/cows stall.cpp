#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<as;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int numStalls,numCows;
        cin>>numStalls;
        cin>>numCows;
        vector<int>stalls;
        stalls.reserve(as);

        for(int j=0;j<numStalls;j++){
            int a;
            cin>>a;
            stalls.push_back(a);
        }
        sort(stalls.begin(),stalls.begin()+numStalls); // sorted the positions

        int max_dist = stalls[numStalls-1]-stalls[0];
        int dist=0;
        for(int j=1;j<=max_dist;j++){
            int cow_count=1;    //placing 1st cow at 1st position
            int lastCowPos=0;   //starting position for 1st cow for each distance is 0th index of stall array
            for(int k=1;k<numStalls;k++){
                if(stalls[k]-stalls[lastCowPos]>=j){    //if distance b/w current position and pos of cow placed last is
                    cow_count++;                        //>= distance we are looping for(j) the update count of cows placed
                    lastCowPos=k;                       // and the last cow placed position
                }
                if(cow_count==numCows){                 //if at any stall in the array all the cows are placed break out
                    dist=j;                             // and update the answer distance
                    break;
                }

            }


        }
        cout<<dist<<endl;


    }


}
