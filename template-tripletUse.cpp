#include <iostream>
using namespace std;

#include "templates.cpp"

int main(){
    Pair<Pair<int,int>,int> p1;
    p1.setY(3);


    Pair<int,int> p2;
    p2.setX(1);
    p2.setY(2);
    p1.setX(p2);
    cout<<p1.getX().getX()<<endl;
    cout<<p1.getX().getY()<<endl;
    cout<<p1.getY()<<endl;
}
