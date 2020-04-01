#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicate(int* arr, int size){
	vector<int> output;
	unordered_map<int,bool> seen;
	for(int i=0;i<size;i++){
		//seen[arr[i]]=true;
		if(seen.count(arr[i])==0){
			seen[arr[i]]=true;
			output.push_back(arr[i]);
		}
	}
	return output;

	//or we could have done
    /*for(int i=0;i<size;i++){
		if(seen.count(arr[i])>0){
                continue;
		}
		seen[arr[i]]=true;
			output.push_back(arr[i]);
	}
	return output;*/
}


int main(){
	int arr[]={1,2,3,3,2,1,4,3,6,5,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	//cout<<size;
	vector<int> ans = removeDuplicate(arr,size);
	//cout<<ans.size();
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<endl;
    }
}
