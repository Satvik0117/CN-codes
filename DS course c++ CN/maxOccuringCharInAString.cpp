#include <iostream>
#include<string>
using namespace std;

int main(){
	string str="aaaaaaaaaaaasfdkcjukabnvdsafehjakbcn";
	int arr[256]={};
	for(int i=0;i<str.length();i++){
		//cout<<str[i]<<endl;
		arr[str[i]]++;
	}
	int max=0;
	int index=0;
	for(int i=0;i<=255;i++){
		if(arr[i]>max){
			max=arr[i];
			index=i;
			//cout<<arr[i]<<endl;
		}

	}
	char c=index;
	cout<<c;
	// char c=i;
	// cout<<c;
	// cout<<str;



}
