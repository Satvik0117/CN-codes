#include <iostream>
using namespace std;
class Complex{
    private:
    int real;
    int img;
    public:
    Complex(int real,int img){
        this->real=real;
        this->img=img;
    }
    void display(){
        cout<<real<<"+j("<<img<<')'<<endl;
    }
    void add(Complex c2){
        real = real + c2.real;
        img = img +c2.img;
    }
    void multiply(Complex c2){
        real =real*c2.real-img*c2.img;
        img=real*c2.img+img*c2.real;
    }
};