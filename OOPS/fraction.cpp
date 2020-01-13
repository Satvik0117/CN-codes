#include <iostream>
using namespace std;

class Fraction{
    private:
    int num;
    int den;
    public:

    Fraction(int num,int den){
        this->num=num;
        this->den=den;
        this->simplify();
    }

    void get(){
        cout<< num <<"/" << den << endl;

    }

    void simplify(){
        int gcd=1;
        int min;
        if(num>den){
            min=den;
        }
        else{
            min=num;
        }
        for(int i=2;i<=min;i++){
            if(num%i==0 && den%i==0){
                gcd=i;
            }
        }
        // cout<<gcd<<endl;
        num=num/gcd;
        den=den/gcd;

    }

    Fraction add(Fraction const &f2){
        int lcm = den*f2.den;
        int x=lcm/den;
        int y=lcm/f2.den;
        int newnum=x*num+y*f2.num;
        int newden=lcm;
        Fraction f3(newnum,newden);
        f3.simplify();
        return f3;

        // simplify();  // means call simplify on this
    
    }
    Fraction operator+(Fraction const &f2) const{  // const function i.e. does not make changes in this obj
        int lcm = den*f2.den;
        int x=lcm/den;
        int y=lcm/f2.den;
        int newnum=x*num+y*f2.num;
        int newden=lcm;
        Fraction f3(newnum,newden);
        f3.simplify();
        return f3;

        // simplify();  // means call simplify on this
    
    }

    bool operator==(Fraction const &f2){
        return (this->num==f2.num && this->den==f2.den);
    }
// Pre increament
    Fraction& operator++(){   //returned fraction to be able to do int i= ++(++j); nesting 
            // added & ie returned by reference to use ++(++f1) because of buffer and stuff see op ovrldng 2.7
        this-> num=this->num +this->den;
        this->simplify();
        // can also do since no other obj involved here
        // num=num+den;
        // simplify();
        return *this;
    }
// Post Increament
    Fraction operator++(int){
        Fraction newf(num,den);
        num=num+den;
        simplify();
        return *this;
    }
    Fraction& operator+=(Fraction const &f2){
         int lcm = den*f2.den;
        int x=lcm/den;
        int y=lcm/f2.den;
        int newnum=x*num+y*f2.num;
        int newden=lcm;
        this->num =newnum;
        this->den=newden;
        simplify();
        // return *this;
    }

}; // class closing 