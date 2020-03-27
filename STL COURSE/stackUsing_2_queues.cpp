#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack{
	queue<T> q1;
	queue<T> q2;

public:

	void push(T data){
		q1.push(data);
	}

	void pop(){

		if(q1.empty()){
			return;
		}
		//move 1st n-1 data to q2

		while(q1.size()>1){
			q2.push(q1.front());
			q1.pop();
		}
		//remove last added element from q1
		q1.pop();
		//interchange names

		// queue<T> temp = q1;
		// q1 = q2;
		// q2 = temp;

		// or
		swap(q1,q2);

	}

	T top(){
		//move 1st n-1 data to q2

		while(q1.size()>1){
			q2.push(q1.front());
			q1.pop();
		}
		T ans =  q1.front();
		q1.pop();
		q2.push(ans);

		swap(q1,q2);
		return ans;
	}

	int size(){
		//cout<< "Size" << q1.size();
		//return q1.size() + q2.size();
        return q1.size();
	}

	bool empty(){
		return size() == 0;
	}


};

int main(){

	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}
