#include <iostream>
#include <algorithm>
using namespace std;


bool compare(int a, int b){
	return a <= b;
}

int main(){
	int coin[] = {1,2,5,10,20,50,100,200,500};
	int n = sizeof(coin)/sizeof(int);
	int money = 168;

	// while(money>0){
		auto it = lower_bound(coin , coin+n, money, compare) - 1 ;
		cout<< *it << " ";
		money-= *it;
	// }

}
