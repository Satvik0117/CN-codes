template <typename T>
class Queue{
    T* data;
    int size;  // the number of elements present at any moment not the kind of size we used in stack and other DS
    int nextIndex;
    int firstIndex;
    int capacity;
public:
    Queue(int s){
    data=new T[s];
    size=0;
    nextIndex=0;
    firstIndex=-1;
    capacity=s;
    }

    int getSize(){
    return size;
    }

    bool isEmpty(){
    return size==0;
    }

    void enqueue(T element){
    if(size == capacity){
        cout<< "Queue is Full" << endl;
        return;
    }
    data[nextIndex]=element;

    nextIndex=(nextIndex+1)%capacity; // important trick
    if(firstIndex==-1)
        firstIndex=0;
    size++;
    }

    T front(){
    return data[firstIndex];
    }

    T dequeue(){
    if(isEmpty()){
        cout<< "Empty Queue" << endl;
        return 0;
    }
    T ans = data[firstIndex];
    firstIndex=(firstIndex+1)%5;
    size--;
    if(size==0){
        firstIndex=-1;
        nextIndex=0;
    }
    return ans;
    }

};
