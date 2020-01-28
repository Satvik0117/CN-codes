#include <iostream>
#include "ourmap.h"
using namespace std;


int main(){
	ourmap<int> map;
	for(int i = 0; i < 10; i++){
		char c = '0'+i;
		string key = "abc";
		key = key + c;
		int value = i+1;
		map.insert(key, value);
		cout<< map.getLoadFactor() <<endl;
	}
	cout<< map.size() <<endl;

    	for(int i = 0; i < 10; i++){
		char c = '0'+i;
		string key = "abc";
		key = key + c;
    	cout<< key <<": " << map.getValue(key) <<endl;
    	}
	map.remove("abc2");
	map.remove("abc7");

	for(int i = 0; i < 10; i++){
		char c = '0'+i;
		string key = "abc";
		key = key + c;
    	cout<< key <<": " << map.getValue(key) <<endl;
    	}
    	cout<< map.size() <<endl;
	/*char c = 97; // this gives c the character which has the ascii value of 97 i.e 'a'
	cout << c << endl;
    char a = '0'+1;   //  is treated as a character
    cout <<a;*/
}
