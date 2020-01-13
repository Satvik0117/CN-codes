#include <iostream>
#include <algorithm>
using namespace std;
class Polynomial{
    int size;
    int* degCoeff;

    public:
    Polynomial(){
        size=5;
        degCoeff=new int[size]{}; //initializing with zeroes
        // cout<<size;
    }
    // Copy Constructor
    Polynomial(Polynomial const &p){
        this->size=p.size;
        // deep copy
        this->degCoeff=new int[p.size];
        for(int i=0;i<size;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
    }
    // Copy Assign Operator 
    void operator=(Polynomial const &p){
        this->size=p.size;
        // deep copy
        this->degCoeff=new int[p.size];
        for(int i=0;i<size;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
    }
    void setCoeff(int deg,int coeff){
        int oldSize=size;
        while(deg>size){
            size=2*size;
        }
        int *newArr= new int[size]{};
        for(int i=0;i<oldSize;i++){
            newArr[i]=degCoeff[i];
        }
        degCoeff=newArr;
        degCoeff[deg]=coeff;
    }
    Polynomial operator+(Polynomial p2){
        Polynomial p3;
        int max=std::max(p2.size,this->size); 
        p3.size=max;
        int min=std::min(p2.size,this->size);
        p3.degCoeff=new int[max]{};
        for (int i=0;i<min;i++){
            p3.degCoeff[i]=this->degCoeff[i]+p2.degCoeff[i];
        }
        if(max==p2.size){
        for (int i=min;i<max;i++){
            p3.degCoeff[i]=p2.degCoeff[i];
         }
        }
        else if(max==this->size){
            for (int i=min;i<max;i++){
            p3.degCoeff[i]=this->degCoeff[i];
         }
        }
        return p3;
    }

 Polynomial operator-(Polynomial p2){
        Polynomial p3;
        int max=std::max(p2.size,this->size); 
        p3.size=max;
        int min=std::min(p2.size,this->size);
        p3.degCoeff=new int[max]{};
        for (int i=0;i<min;i++){
            p3.degCoeff[i]=this->degCoeff[i]-p2.degCoeff[i];
        }
        if(max==p2.size){
        for (int i=min;i<max;i++){
            p3.degCoeff[i]=-p2.degCoeff[i];
         }
        }
        else if(max==this->size){
            for (int i=min;i<max;i++){
            p3.degCoeff[i]=this->degCoeff[i];
         }
        }
        return p3;
    }
    Polynomial operator*(Polynomial p2){
        Polynomial prod;
        prod.degCoeff = new int[p2.size+this->size-1]{}; 
        int m=this->size;
        int n=p2.size;
   // Initialize the porduct polynomial 
  
  
   // Multiply two polynomials term by term 
  
   // Take ever term of first polynomial 
   for (int i=0; i<m; i++) 
   { 
     // Multiply the current term of first polynomial 
     // with every term of second polynomial. 
     for (int j=0; j<n; j++) 
         prod.degCoeff[i+j] += this->degCoeff[i]*p2.degCoeff[j]; 
   } 
  
   return prod; 
} 
        
        
        // return p3;
    
    void print(){
        //   cout<<size<<endl;

        for(int i=0;i<size;i++){
            if(i==size-1)
                cout<<degCoeff[i]<<"x^("<<i<<")"<<endl;
            else
                cout<<degCoeff[i]<<"x^("<<i<<")+";
        }
    }
};