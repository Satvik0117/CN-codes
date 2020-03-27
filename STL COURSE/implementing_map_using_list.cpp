#include <iostream>
#include <list>
#include <utility>
using namespace std;


int main(){
	int n;
	cin >> n;	//no of points

	list<pair<int,int>> l[n];

		int edges;	//total number of edges in the map
		cin >> edges;

		for(int j=0;j<edges;j++){
			int x,y,wt;
			l[x].push_back(make_pair(y,wt));
			l[y].push_back(make_pair(x,wt));	//for bidirectional edge
		}



	for(int i=0;i<n;i++){
		cout<<"LL " << i <<" ";
		for(auto ent: l[i]){
			cout<<"("<<ent.first<<","<<ent.second <<")-->";
		}
		cout<<endl;
	}

}
