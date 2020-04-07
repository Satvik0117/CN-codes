#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}

int main() {

	int T;
	cin >> T;


	for(int j =0; j<T; j++ ){
		int n;
		cin>>n;

		vector<pair<int,int>> activities;
		
		for(int i=0;i<n;i++){
			pair<int,int> p;
			cin >> p.first;
			cin >> p.second;
			activities.push_back(p);
		}


		sort(activities.begin(),activities.end(),compare);

        // for(int i=0;i<n;i++){
        //     cout<< activities[i].first << " "<<activities[i].second<<endl;
        // }
        
		vector<int> poss_act;

		int num=1;
		int i=0;
		//first activity ends first=> it must have started 1st and it would be in the ans for sure -- NO WRONG STATEMENT

		for(int k=1;k<n;k++){
			if(activities[i].second <= activities[k].first){
				i=k;		// i are the activities which are inculded in the ans
				num++;		
			}
			
		}

	cout<<num<<endl;


	}


	return 0;
}