#include<iostream>
using namespace std;


void removeDuplicates(char s[]){
	if(s[0]=='\0'){
		return;
	}
	if(s[0]==s[1]){
		int i=1;
		for(;s[i];i++){
			s[i-1]=s[i];
		}
		s[i-1]=s[i];
		removeDuplicates(s);
	}
	else{
		removeDuplicates(s+1);
	}


}

int main(){
	char s[100];
	cin>>s;
	removeDuplicates(s);
	cout<<s;
}
