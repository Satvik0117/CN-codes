template<typename T>
class Stacks{
    T* data;
    int nextIndex;
    int capacity;

    public:

     Stacks(){
     data=new T[3];
     nextIndex=0;
     capacity=3;
     }
     int size(){
     return nextIndex;
     }
     void push(T d){
          if(nextIndex==capacity){
          // cout<< "Stack Full"<<endl;
            T* newData= new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newData;

          }
     data[nextIndex]=d;
     nextIndex++;
     }

     T pop(){
         if(isEmpty()){
            cout<<"Empty Stack";
            return 0;   //Will work with every data type IMPORTANT
         }
     nextIndex--;
     return data[nextIndex];
     }


     T top(){
     if(isEmpty()){
            cout<<"Empty Stack"<<endl;;
            return 0;
         }
     return data[nextIndex-1];
     }
     bool isEmpty(){
     /*if(nextIndex==0)
        return true;
     return false;
     }
     */
     return nextIndex==0;
}

};
