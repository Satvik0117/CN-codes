#include<iostream>
using namespace std;


int merge(int a[],int left,int mid,int right){
	int i=left,j=mid+1,k=0;
	int temp[right-left+1];
	int sum=0;
	while(i<=mid && j<=right){
		if(a[i] < a[j]){

 			cout<<"--> "<<a[i]<<" "<< right-j+1<<endl;
			sum = sum+ a[i]*(right-j+1);
			temp[k++] = a[i++];
		}else{

			temp[k++] = a[j++];
		}
	}
	while(i<=mid){
		temp[k++] = a[i++];
	}
	while(j<=right){
		temp[k++] = a[j++];
	}

	for(int i=left,k=0;i<=right;i++,k++){
		a[i] = temp[k];
	}

	return sum;

}

int merge_sort(int a[],int l,int r){

	if(r>l){
		int mid=(l+r)/2;
		int leftCount =merge_sort(a,l,mid);
		int rightCount = merge_sort(a,mid+1,r);
		int mergeCount = merge(a,l,mid,r);
		return leftCount+rightCount+mergeCount;
	}
	return 0;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		int ans = merge_sort(a,0,n-1);
		cout<<ans<<endl;
	for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
	}	
}