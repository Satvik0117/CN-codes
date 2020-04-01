
// https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/



#include <iostream>
using namespace std;


int min_count_recursive(int n){
	if(n==1){
		return 1;
	}
	return 1+min_count_recursive(n-1*1);


}

int main(){
	int data;
	cin>>data;
	cout << min_count_recursive(data);


}
