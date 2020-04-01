#include <iostream>
using namespace std;

#include "fraction.cpp"

int main(){
    Fraction f1(10,3);
    // f1.get();
    Fraction f2(5,2);
    // f2.simplify();
    // cout<<&f2<<endl;
    // Fraction f3=f1.add(f2);
    // f3.get();
    // f1.get();
    // Fraction f4=f1+f2;
    // f4.get();
    // if(f1==f2)
        // cout<< "equal";
        // Fraction f4=++f1;
        (f1+=f2)+=f2;
        f1.get();
        // f4.get();
}