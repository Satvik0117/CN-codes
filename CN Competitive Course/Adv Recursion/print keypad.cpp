#include<iostream>
#include<string>
using namespace std;
string check(int num){
    string s;
    switch(num){
        case 0:
            s="";
            break;
        case 1:
            s="";
            break;
        case 2:
            s="abc";
            break;
        case 3:
            s="def";
            break;
        case 4: 
            s="ghi";
            break;
        case 5:
            s="jkl";
            break;
        case 6: 
            s="mno";
            break;
        case 7:
            s="pqrs";
            break;
        case 8:
            s="tuv";
            break;
        case 9:
            s="wxyz";
            break;
    }
    return s;
}

void printKeypad(int num, string output){
	if(num==0){
		cout<<output<<endl;
		return;
	}
	string s = check(num%10);
	for(int i=0;i<s.length();i++){
        printKeypad(num/10,s[i]+output);
    }


}

int main(){

	int n;
	cin>>n;
	string output="";
	printKeypad(n,output);

}