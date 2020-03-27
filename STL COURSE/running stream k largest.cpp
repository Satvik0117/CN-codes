#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;


void printQuery(auto pq){
	while(!pq.empty()){
		cout<< pq.top()<<' ';
		pq.pop();
	}
	cout <<endl;
}


int main(){
	int n;
	int cs = 0;

int k=3;

	priority_queue<int,vector<int>,greater<int>> pq;
	while(scanf("%d",&n)!=EOF){
		if(n== -1){
			printQuery(pq);
		}
		else if(cs < k){
			pq.push(n);
			cs++;
		}
		else if(n > pq.top()){
			pq.pop();
			pq.push(n);
		}

	}

}