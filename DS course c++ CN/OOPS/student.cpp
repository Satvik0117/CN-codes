#include <iostream>
using namespace std;
#include <cstring>
class Student{

    public:
    char* name;
    int age;
    int rollNo; //to understand initialization list - used to initialize const data members while allocating
                      // memory. It is must to create const if we have const data mem or reference variables
    //int &x;
    static int totalStudents; // initialised out of the class
    /*Student(int age,int rollNo):rollNo(rollNo),age(age),x(this->age){
        totalStudents++;
    }*/
   /* Student(){
        totalStudents++;
        cout<<"a"<<endl;
    }*/
    // Student( Student const &s2){
    //     this->age=s2.age;
    //     cout<<age<<endl;
    //     //shallow copy
    //     //this->name=name;

    //     //Deep Copy
    //     this->name= new char[strlen(s2.name)+1];
    //     strcpy(this->name,s2.name) ;
    // }

    void display(){
        cout<<"Age is: " <<age  << endl;
        cout<<"Name is: " << name   << endl;
    }

};

    int Student :: totalStudents=0; // initializing static data member
