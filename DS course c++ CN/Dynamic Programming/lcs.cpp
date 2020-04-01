#include <iostream>
#include <string>
using namespace std;


const int maximum = 10;

int LCS(string a, string b, int a1, int b1){

	if(a1 == 0 || b1 == 0){
		return 0;
	}

	if(a[0] == b[0]){
		return 1+LCS(a.substr(1) , b.substr(1), a1-1, b1-1);
	}

	// int op1 = LCS(a.substr(1) , b.substr(1), a1-1, b1-1 );	not needed
	int op2 = LCS(a , b.substr(1), a1, b1-1 );
	int op3 = LCS(a.substr(1) , b, a1-1, b1 );

	// return max(op1, max(op2, op3));
	return max(op2, op3);
}

// memoizationmaximum
int lcsHelper_M( int storage[][maximum] , string a, string b, int m, int n){
	if(storage[m][n] != -1){
		return storage[m][n];
	}
	if(m == 0 || n == 0){
		storage[m][n] = 0;
		return 0;
	}
	if( a[0] == b[0]){
		storage[m][n] = 1 + lcsHelper_M(storage, a.substr(1), b.substr(1), m-1, n-1);
		return storage[m][n];
	}
	int op1 = LCS(a , b.substr(1), m, n-1 );
	int op2 = LCS(a.substr(1) , b, m-1, n );

	storage[m][n] = max(op1, op2);
	return storage[m][n];
}

int lcs_M(string a, string b, int m, int n){
    //cout<<m<<n;
	int storage[m+1][maximum];
	for( int i=0; i< m+1; i++){
		for( int j=0; j < n+1; j++){
			storage[i][j] = -1;
		}
	}

	return lcsHelper_M(storage, a, b, m, n);
}


int lcsDP(string a, string b, int m, int n){
	int storage[m+1][n+1];
	for(int i=0; i < n+1; i++){
		storage[0][i] = 0;
	}
	for(int i=0; i < n+1; i++){
		storage[i][0] = 0;
	}

	for(int i=1; i<m+1; i++){
		for( int j=1; j<n+1; j++){
			if(a[m-i] == b[n-j]){
				storage[i][j] = 1 + storage[i-1][j-1];
			}else{
				storage[i][j] = max(storage[i-1][j] , storage[i][j-1]);
			}

		}
	}

	return storage[m][n];
}

int main(){
	string a = "adiwefabcdqwert";
	string b = "gdiveqfadeqty";
	// cout<<a.length();
	// cout<<b.length();
	int m = a.length();
	int n = b.length();
	// int storage[m+1][maximum];
	// for( int i=0; i< m+1; i++){
	// 	for( int j=0; j < n+1; j++){
	// 		storage[i][j] = -1;
	// 	}
	// }


	cout << lcsDP( a ,b ,a.length(), b.length())<< endl;
	cout << lcs_M( a ,b ,a.length(), b.length())<< endl;
	cout << LCS(a ,b ,a.length(), b.length())<< endl;
}
