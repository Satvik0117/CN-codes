#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


template<class Iterator,class T>
Iterator search(Iterator begin, Iterator end, T data){
	while(begin != end){
		if(*begin == data){
			break;
		}
		begin++;
	}
	return begin;

}

class Book{
public:
	string name;
	int price;
public:
	Book(string name, int price){
		this->name = name;
		this->price = price;
	}

};


class BookComparator{
public:
	bool operator()(Book b1, Book b2){
		if(b1.name == b2.name)
			return true;
		return false;
	}
};

class intComparator{
public:
	bool operator()(int a, int b){
		if(a == b)
			return true;
		return false;
	}
};

template<class Iterator,class T, class Comparator>
Iterator search(Iterator begin, Iterator end, T key, Comparator cmp){
	while(begin != end){
		if(cmp(*begin, key)){
			cout<<'#';
			break;
		}
		begin++;
	}
	return begin;

}


int main(){
	int arr[] = {0,1,2,3,4,5};
	int* end = &arr[5];
	// Note
	int* it1 = search(arr,&arr[5], 4);
	auto it2 = search(arr,&arr[5], 3);

	// cout << *it1<<endl;
	// cout << *it2<<endl;

	Book b1("c++", 700);
	Book b2("java", 1100);
	Book b3("python", 1200);
	vector<Book> l1 ;	// will work with list also
	l1.push_back(b1);
	l1.push_back(b2);
	l1.push_back(b3);

	Book bookToFind("c++",1200);
    BookComparator cmpB;


	auto book_it = search(l1.begin(), l1.end(), bookToFind, cmpB);

	intComparator cmpInt;
	auto int_it = search(arr, &arr[5], 4, cmpInt);
	cout<<*int_it<<endl;
	// auto will bededuced to list<book>::iterator
	cout << (*book_it).name << " " << (*book_it).price;
}


// See 90 and 87 both call are free from under lying data types(key and type of containers) becaz of TEMPLATES and 
// free from the containers used becaz of ITERATORS and 
// underlying operations becaz of COMPARATORS