#include <iostream>
using namespace std;

#include <queue>


int main(){
	//priority_queue<int> pq; //max PQ
	priority_queue<int, vector<int>, greater<int> > pq; // min PQ

	pq.push(100);
	pq.push(21);
	pq.push(45);
	pq.push(15);
	pq.push(5);
	pq.push(215);

/*	cout<< pq.size()<<endl;
	cout<< pq.top()<<endl;
	cout<< pq.empty()<<endl;
*/
    for(int i=0; i < 6; i++){
		cout<< pq.top() << " ";
		pq.pop();

	}
}
