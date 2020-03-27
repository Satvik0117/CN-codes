#include <iostream>
#include <string>

using namespace std;

int main(){

	//C type
	char str[] = "gfg";
	cout<<str<<endl;

	char str1[] = {'g', 'f', 'g', '\0'};
	cout<<str1<<endl;


	// string class
	string str2 = "qwertyui";
	cout<<str2.length()<<endl;

	string s3(4,'a');
	cout<<s3<<endl;
	cout<<s3.length();

	string s4(str2,2,5);
	cout<<s4<<endl;

	cout<<str2.find("erty");

}
