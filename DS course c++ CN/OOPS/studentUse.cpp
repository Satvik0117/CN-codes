#include <iostream>
using namespace std;

#include "student.cpp"

int main(){
//Student s1(21,21);
//Student s2(21,21);
Student s1();
cout<<"s1: ";
s1.display();
Student s3=Student();
s3.display();
Student* s4=new Student;
s4->display();
Student* s5=new Student();
(*s5).display();
// s1.rollNo=12342;
// s1.age=20;
// char a[]="Satvik";
cout<< Student :: totalStudents ;
// s1.name=a;
// s1.display();
// Student s2(s1);
// s2.name[2]='z';
// s2.display();
}
