#include <iostream>
using namespace std;

//normal recursion
int min_steps_to_1(int n){
    if(n==1){
        return 0;
    }
	int ans_1 = INT_MAX;
	int ans_2 = INT_MAX;
	int ans_3 = INT_MAX;
	ans_1 = min_steps_to_1(n-1);
	if(n%2==0){
		ans_2 = min_steps_to_1(n/2);
	}
	if(n%3==0){
		ans_3 = min_steps_to_1(n/3);
	}
	int minimum = min(ans_1 , min(ans_2, ans_3));
	return	minimum+1;
}

//memorization
//same code + arr which stores prv calls for reference if again called
int min_steps(int n, int* arr){
	if(n==1){
		// arr[1]=0;
		return 0;
	}
	int ans_1 = INT_MAX;
	int ans_2 = INT_MAX;
	int ans_3 = INT_MAX;
	if(arr[n-1]==0){
	ans_1 = min_steps_to_1(n-1);
	arr[n-1] = ans_1;
	}else{
		ans_1 = arr[n-1];
	}
	if(n%2==0){

		if(arr[n/2]==0){
		ans_2 = min_steps_to_1(n/2);
		arr[n/2] = ans_2;
		}else{
			ans_2 = arr[n/2];
		}

	}
	if(n%3==0){
		if(arr[n/3]==0){
		ans_3 = min_steps_to_1(n/3);
		arr[n/3] =ans_3;
		}else{
			ans_3 = arr[n/3];
		}
	}
	int minimum = min(ans_1 , min(ans_2, ans_3));
	return	minimum+1;
}

int min_steps(int n){
	int* arr = new int[n+2];
	 for(int i=0; i <= n+1; i++){
    	arr[i] = 0;
    }
	return min_steps(n , arr);
}

//DP
int min_steps_DP(int n){
	int arr[n+1]{};
	arr[1] = 0;
	// arr[2] = 1;
	for( int i = 2; i<=n; i++){
		int ans_1 = arr[i-1];
		int ans_2 = INT_MAX;
		int ans_3 = INT_MAX;
		if(i%2==0){
			ans_2 = arr[i/2];
		}
		if(i%3==0){
			ans_3 = arr[i/3];
		}
		int minimum = min( ans_1, min(ans_3,ans_2));
		arr[i] = minimum + 1;
	}
	return arr[n];
}



int main(){
	int data;
	cin >> data;
	cout<< min_steps(data)<<endl;
	cout << min_steps_to_1(data)<<endl;
	cout << min_steps_DP(data);

}
