#include <iostream>
using namespace std;

int main(){
int i=0;
int const &k=i;
cout<<"k is";
cout << k <<" "<<endl;
cout<<"i is"<< i <<endl;
k++;
cout << k<<endl;
i++;
cout << i <<endl;
}