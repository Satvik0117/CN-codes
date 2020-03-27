#include <iostream>
#include <string>
#include <utility>
using namespace std;


pair<char,int> func(string str){
	int arr[256]= {};

	for(int i=0;i<str.length();i++){
		arr[str[i]] += 1;
	}
	int max_fq=0;
	char c;
	for(int i=0; i<256; i++){
		if(arr[i]>max_fq){
			max_fq = arr[i];
			c = char(i);
		}
	}

	pair<char, int> p;
	p.second = max_fq;
	p.first = c;
	return p;
}


int main(){
	string str = "adsfgwfbgsafgfbedbmdjuxjdnaafafa";
	pair<char,int> p = func(str);
	cout << p.first << " " << p.second;
}
