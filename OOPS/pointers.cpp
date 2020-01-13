#include <iostream>
using namespace std;

// https://www.tutorialspoint.com/cplusplus/cpp_pointers_vs_arrays.htm
// https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/
// https://www.mathwarehouse.com/programming/passing-by-value-vs-by-reference-visual-explanation.php
// https://www.quora.com/Why-does-using-only-the-name-of-a-character-array-print-the-whole-array-in-C
int main(){
    int i;

    // cout << &i<<endl;       // address of var 'i'

    int* p;                 //initialising pointer var

    // cout << &p<<endl;       // address of pointer var

    p=&i;                   //assigning value to pointer var i.e. address of var 'i'
    
    // cout << p<<endl;        //gives value of point var p i.e. address of var 'i'

    char a='a';
    char b[]="adsfvs";

    cout << a << endl;
    // cout << &a << endl;
    // cout << &a[0] << endl;
    // cout << a[1] << endl;
    //  cout << 'b' << endl;

     cout << b << endl;
     
    cout << &b << endl;
    cout <<*(b+1) << endl;
    cout << b[1] << endl;

      char* name;
    char asd[]="sadf";
    name =asd;
    cout<< asd<<" "<<name<<endl;
    int* a;
    int x=3;
    a=&x;
    cout<<*a;
}