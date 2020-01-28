#include <iostream>
using namespace std;

int main(){
//making an array of pointers
    int* b=new int; // variable
    int* arr1;
    int p=5;
	int* a =&p;
    arr1=new int[5];//array of data type int

	int** arr;

	arr=new int*[5]; //array of pointers of type int

	//arr[0]=a;

	arr[0]=a;

	cout<<arr<<endl;
	cout<<*arr[0]<<endl;
	cout<<arr[0]<<endl;
	cout<<a<<endl;
//	arr[0]=a;
//	cout<<*arr[0];

}
