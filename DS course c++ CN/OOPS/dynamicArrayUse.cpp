#include <iostream>
using namespace std;

#include "dynamicArray.cpp"

int main(){
    DynamicArray d1;
    d1.add(3);
    d1.add(21);
    d1.add(62);
    d1.add(21);
    d1.add(17);
    d1.add(11);
    d1.print();
    DynamicArray d2(d1); //Copy Constructor will be called  -- does shallow copy
    DynamicArray d3=d1; //copy assignment operator also does shallow copying but we made our own with deep copy
    
    d1.add(0,100);
    d2.print();

}