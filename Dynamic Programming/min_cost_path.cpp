// https://www.geeksforgeeks.org/how-to-print-size-of-an-array-in-a-function-in-c/
#include <iostream>
using namespace std;

//Normal Recursion
int min_cost_path(int arr[3][3],int m, int n, int i, int j){
    	// cout <<"ROW"<< sizeof arr/sizeof arr[0]<<endl;
	// cout << sizeof arr[0]/sizeof(int)<<endl;
    // int m = sizeof arr/sizeof arr[0];
    // int n = sizeof arr[0]/sizeof(int);
    if(i == m-1 && j == n-1){
        return arr[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }
    int ans_1 = min_cost_path(arr,3,3,i+1,j);
    int ans_2 = min_cost_path(arr,3,3,i,j+1);
    int ans_3 = min_cost_path(arr,3,3,i+1,j+1);
    int ans = min(ans_1,min(ans_2,ans_3)) + arr[i][j];
    return ans;
}

int min_cost_path(int arr[3][3], int m, int n){
    // cout<<arr[1][2]<<endl;
	return min_cost_path(arr,3, 3, 0, 0);
}

// Memoization{}
int min_cost_better(int arr[3][3], int storage[3][3],  int m, int n, int i, int j){
	if(i == m-1 && j == n-1){
		storage[i][j] = arr[i][j];
		return arr[i][j];
	}

	if(i >= m || j >= n){
		return INT_MAX;
	}
	int ans_1;
	if(storage[i+1][j] == -1){
		storage[i+1][j] = min_cost_better(arr, storage, m, n, i+1, j);
	}
	ans_1 = storage[i+1][j];
	int ans_2;
	if(storage[i+1][j+1] == -1){
		storage[i+1][j+1] = min_cost_better(arr, storage, m, n, i+1, j+1);
	}
	ans_2 = storage[i+1][j+1];
	int ans_3;
	if(storage[i][j+1] == -1){
		storage[i][j+1] = min_cost_better(arr, storage, m, n, i, j+1);
	}
	ans_3 = storage[i][j+1];
	int ans = min(ans_1,min(ans_2,ans_3)) + arr[i][j];
    return ans;

}

int min_cost_better(int arr[3][3], int m, int n){
	int storage[3][3];
	for(int j=0; j <m; j++){
		for(int i=0; i <n; i++){
			storage[i][j] = -1;
		}
	}
	return min_cost_better(arr, storage, m , n, 0, 0);
}

int min_cost_path_DP(int arr[3][3]){

}

int main(){
	int arr[3][3] = {{1,1,1},{4,5,2},{7,8,9}};
	cout <<"Row" <<sizeof arr/sizeof arr[0]<<endl;
	cout <<"Column" << sizeof arr[0]/sizeof(int)<<endl;

    cout<<min_cost_path(arr,3,3)<<endl;
    cout << min_cost_better(arr, 3, 3);
}
