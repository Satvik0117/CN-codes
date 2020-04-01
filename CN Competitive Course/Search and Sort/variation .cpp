// https://www.codechef.com/ZCOPRAC/problems/ZCO15002

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	//2 pointer approach
	// int i=0,j=1;
	// int count=0;
	// while(j<n){
	//     if(arr[j]-arr[i]>=k){
	//         count+=n-j;
	//         i++;
	//     }else{
	//         j++;
	//     }
	// }
	// cout<<count<<endl;

	//TC :- nlogn + n   sorting + traversal over the array


	//binary approach
	int count1=0;
	for(int i=0;i<n;i++){
		int left=i, right=n-1;
		int smallest_index=n;	//if index is not updated count will be 0 for this(n-n)
		while(left<=right){
			int mid=(left+right)/2;
    //        cout<<mid<<endl;
			if(arr[mid]-arr[i]>=k){
				right=mid-1;
				smallest_index = mid;
			}else{
				left=mid+1;
			}
		}
		count1 += n-smallest_index ;
	}
	cout<<count1<<endl;

	return 0;
}
