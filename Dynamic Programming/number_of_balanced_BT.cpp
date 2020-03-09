#include <iostream>
using namespace std;

int noOfBalancedBT(int h){
	if(h==1 || h==0){
		return 1;
	}
	int a = noOfBalancedBT(h-1);
	int b = noOfBalancedBT(h-2);
	return 2*a*b + a*a;
}

int main(){
	int height;
	cin>> height;
	cout<< noOfBalancedBT(height)<<endl;
}
