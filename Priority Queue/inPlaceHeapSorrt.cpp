#include <iostream>
using namespace std;


int* inPlaceHeapSort(int* arr, int size){
	//insertion part i.e. build the heap in the input array only
	for(int i = 1; i < size; i++){
		int childIndex = i;
		while(childIndex > 0){
			int parentIndex = (childIndex-1)/2;
			if( arr[childIndex] < arr[parentIndex]){
				int temp = arr[childIndex];
				arr[childIndex] = arr[parentIndex];
				arr[parentIndex] = temp;
				childIndex = parentIndex;
			}else{
				break;
			}
		}
	}

	//removal part

	while(size>1){
		//swap 1st and last element

		int temp = arr[0];
		arr[0] = arr[size-1];
		arr[size-1] = temp;
		size--;

		int parentIndex = 0;
		int leftChildIndex = 2* parentIndex+1;
		int rightChildIndex =2* parentIndex+ 2;
		while(leftChildIndex < size ){
			int minIndex = parentIndex;

			if(arr[leftChildIndex] < arr[minIndex]){
				minIndex = leftChildIndex;
			}
			if( rightChildIndex < size && arr[rightChildIndex] < arr[minIndex]){
				minIndex = rightChildIndex;
			}
			if(minIndex == parentIndex){
				break;
			}
			int temp = arr[minIndex];
			arr[minIndex] = arr[parentIndex];
			arr[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;
		}

	}


	return arr;
}


int main(){

    int* arr = new int[5]{5,1,2,0,8};
	arr = inPlaceHeapSort(arr,5);
	for(int i=0 ; i< 5;i++){
    cout<< arr[i]<< " ";
	}
}
