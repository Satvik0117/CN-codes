#include <iostream>
using namespace std;

class DynamicArray{
int *data;
int nextIndex;
int size;

public:
DynamicArray(){
    data=new int[5];
    size=5;
    nextIndex=0;
    }
DynamicArray(DynamicArray const &d){
    // this->data=d.data;     // shallow copy

    // Deep Copy
    int *data=new int[d.size];
    for (int i=0;i<d.nextIndex;i++){
       this-> data[i]=d.data[i];
    }

    this-> nextIndex=d.nextIndex;
    this-> size=d.size;

}
// Made our own Copy Assignment Operator
void operator=(DynamicArray d){
    // Deep Copy
    int *data=new int[d.size];
    for (int i=0;i<d.nextIndex;i++){
       this-> data[i]=d.data[i];
    }

    this-> nextIndex=d.nextIndex;
    this-> size=d.size;    
}

void print(){
    int i;
    for (i=0;i<nextIndex;i++){
        cout<<data[i]<<endl;
    }
    cout<<"No. of elements : "<<i+1<<endl;
}

void add(int element){
    if(nextIndex==size){
        // create an array double the size of existing array and copy elements
        int *newArr=new int[2*size];
        for(int i=0;i<size;i++){
            newArr[i]=data[i];
        }
        delete [] data;
        data=newArr;
        size*=2;
    }
    
    data[nextIndex]=element;
    nextIndex++;

}

int get(int i){
    if(i<nextIndex)
        return data[i];
    else 
        return -1; 
}

void add(int i,int element){
    if(i<nextIndex){
        data[i]=element;
    }
    else if(i==nextIndex){
        add(element);
    }
    else if(i>nextIndex)
        return;

}



};