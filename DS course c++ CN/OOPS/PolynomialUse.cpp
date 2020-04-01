#include <iostream>
#include <algorithm>
using namespace std;

#include "polynomial.cpp"

int main(){
// cout<< std::max(3,4);
Polynomial p1;
p1.setCoeff(3,-4);
p1.setCoeff(1,1);
p1.setCoeff(2,2);
// p1.setCoeff(11,-7);
// p1.print();



Polynomial p2(p1);
Polynomial p3=p1;

// p1.setCoeff(7,7);


Polynomial p4=p1*p2;
// Polynomial p5=p2-p1;
p1.print();
p2.print();
p4.print();
// p2.print();
// p3.print();

}
