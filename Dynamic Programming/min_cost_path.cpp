// https://www.geeksforgeeks.org/how-to-print-size-of-an-array-in-a-function-in-c/
#include <iostream>
using namespace std;

//Normal Recursion
int min_cost_path(int arr[3][3],int m, int n, int i, int j){
    	// cout <<"ROW"<< sizeof arr/sizeof arr[0]<<endl;
	// cout << sizeof arr[0]/sizeof(int)<<endl;
    // int m = sizeof arr/sizeof arr[0];
    // int n = sizeof arr[0]/sizeof(int);
    // cout <<"!"<<endl;
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

	if(storage[i][j] != -1){
		return storage[i][j];
	}

	int ans_1 = min_cost_path(arr,3,3,i+1,j);
    int ans_2 = min_cost_path(arr,3,3,i,j+1);
    int ans_3 = min_cost_path(arr,3,3,i+1,j+1);
    storage[i][j] = min(ans_1,min(ans_2,ans_3)) + arr[i][j];
    return storage[i][j];

}

// need to handel storage array better
 // see https://www.geeksforgeeks.org/longest-common-subsequence-dp-using-memoization/
// https://www.tutorialspoint.com/Passing-two-dimensional-array-to-a-Cplusplus-function
int min_cost_better(int arr[3][3], int m, int n){
	int storage[3][3];
	for(int i=0; i <m; i++){
		for(int j=0; j <n; j++){
			storage[i][j] = -1;
		}
	}
	return min_cost_better(arr, storage, 3 , 3, 0, 0);
}

int min_cost_path_DP(int arr[3][3]){
	int storage[3][3]
}

int main(){
	int arr[3][3] = {{1,1,1},{4,5,2},{7,8,9}};
	//cout <<"Row" <<sizeof arr/sizeof arr[0]<<endl;
	//cout <<"Column" << sizeof arr[0]/sizeof(int)<<endl;

    cout<<min_cost_path(arr,3,3)<<endl;
    cout << min_cost_better(arr, 3, 3);
}
