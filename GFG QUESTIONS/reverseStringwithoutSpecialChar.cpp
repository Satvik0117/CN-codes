// https://www.geeksforgeeks.org/reverse-a-string-without-affecting-special-characters/
#include <iostream>
#include <string>
using namespace std;


bool isAlphabet(char x){
	// if((x >= 'A' && x <='Z') || (x >='a' && x <= 'b')){
	// 	return true;
	// }
	// return false;

	return ((x >= 'A' && x <='Z') || (x >='a' && x <= 'z'));
}

string reverse(string a , int n){
	char temp[n];
	int j=0;
	for(int i=0 ; i < n; i++){
		// cout<<isAlphabet(a[i])<<endl;
		if(isAlphabet(a[i])){
		//    cout<<a[i];
                // cout<<i;
			temp[j] = a[i];
			j++;
		}
	}

	// cout<<temp<<endl;
	int k=0;
	for(int i=0; i<n;i++){
		if(isAlphabet(a[i])){
			if(j-1-k < 0)
				break;
			a[i] = temp[j-1-k];
			k++;
		}
	}
	//cout<<temp.length();
	// cout<<a;
	return a;
}

void swap(char* a, char* b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

string reverse_better(string a, int n){
	int l=0;
	int r=n-1;
	while(l<r){
		if(isAlphabet(a[l]) && isAlphabet(a[r])){
			swap(&a[l], &a[r]);
			l++;
			r--;
		}
		if (!isAlphabet(a[l])) 
            l++; 
        else if(!isAlphabet(a[r])) 
            r--; 
	}
	return a;
}

int main(){

	int t;
    cin >> t;
	    for(int i=1;i<=t;i++){
		string s1;
		cin >> s1;
		//cout << bool('a'>'A');
		string ans1 = reverse(s1, s1.length());
		string ans2 = reverse_better(s1, s1.length());
		cout<< ans2<<endl;
		cout<< ans1;
		}
}
