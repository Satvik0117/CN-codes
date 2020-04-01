#include <iostream>
using namespace std;


long long merge(int A[],int left,int mid,int right){	//mid here is index at which right part of array starts

	int i=left, j=mid, k=0;
	int temp[right-left+1];
	long long count =0;
	while(i < mid && j<=right ){
		if(A[i] <= A[j]){
			temp[k++] = A[i++];
		}else{
			temp[k++] = A[j++];
			count += mid-1 - i +1;	//mid-i
		}
	}

	while(i<mid){
		temp[k++] = A[i++];
	}
	while(j<=right){
		temp[k++] = A[j++];
	}

	for(int i = left,k=0; i<=right;i++,k++){
		A[i] = temp[k];
	}

	return count;

}



long long merge_sort(int A[], int left, int right){
	long long count=0;
	if(right > left){
		long long mid = left + (right-left)/2;

		long long leftCount = merge_sort(A,left,mid);
		long long rightCount = merge_sort(A,mid+1,right);
		long long mergeCount = merge(A,left,mid+1,right);

		return leftCount+rightCount+mergeCount;

	}

	return count;
}


long long solve(int A[], int n){
	long long ans = merge_sort(A,0,n-1);
	return ans;
}