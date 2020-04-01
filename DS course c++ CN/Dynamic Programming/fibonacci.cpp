#include <iostream>
using namespace std;


int fibonacci(int n){
	if(n<=1){
		return n;
	}
	int a = fibonacci(n-1);
	int b = fibonacci(n-2);
	return a+b;
}
int fib_better_helper(int n, int* arr);

int fib_better(int n){
    int* arr = new int[n+1];
    for(int i=0; i <= n; i++){
    	arr[i] = 0;
    }
    return fib_better_helper(n, arr);

}
int fib_better_helper(int n, int* arr){
	if(n<=1){
		arr[n] = n;
		return n;
	}
	if(arr[n-1]==0){
		arr[n-1]=fib_better_helper(n-1,arr);
		// arr[n-1];
	}
	if(arr[n-2]==0){
		arr[n-2]=fib_better_helper(n-2,arr);
		// arr[n-2];
	}
	arr[n] = arr[n-1] + arr[n-2];
	return arr[n];

}



int fibo_DP(int n){
	int* arr = new int[n+1];
	// for(int i=0; i < n+1; n++){
	// 	arr[i] = 0;
	// }
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2 ; i<=n+1; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	// return fibo_DP(n, arr);
	return arr[n];
}

int main(){
    int data;
    cin>>data;
    cout<<fib_better(data)<<endl;
    cout<<fibo_DP(data)<<endl;
    cout<<fibonacci(data)<<endl;
}