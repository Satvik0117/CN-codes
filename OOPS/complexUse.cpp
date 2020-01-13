#include <iostream>
using namespace std;

#include "complex.cpp"

int main(){
Complex c1(2,-3);
c1.display();
Complex c2(1,1);
c1.multiply(c2);
c1.display();

}