#include <iostream>
#include <cstring>
using namespace std;


char* myStrTok(char* s, char delim){	//we are taking single charfor easy implimentation, otherwise ti would be a string

		static char* input = NULL;
		//only initialising if string is passed , to work for 2nd,3rd.... calls (null calls for next tokens)
		if(s != NULL){
			input = s;
		}
		if(input==NULL){
			return NULL;
		}

		char* output = new char[strlen(input)+1];
		int i =0;
		for(; i <input[i]!='\0';i++){
			if(input[i]!=delim){
				output[i] = input[i];
			}
			//else will get executed only once becaz return
			else{
				output[i]='\0';
				input = input + i +1;
				return output;
			}
		}
		//corner case
		output[i] = '\0';
		input = NULL;
		return output;



}

int main(){
	char str[100]="asd,fgh,jkl";
	//cout<<myStrTok(str,',')<<endl;
	//while(myStrTok(NULL,',')!=NULL){  can't use this as it considers while condition as a call and returns string hence we miss a token
	//	cout<<myStrTok(NULL,',')<<endl;
	//}
	char* ptr = myStrTok(str,',');
	cout<<ptr<<endl;
	while(ptr!=NULL){
		ptr = myStrTok(NULL,',');
		cout << ptr <<endl;
	}


}
