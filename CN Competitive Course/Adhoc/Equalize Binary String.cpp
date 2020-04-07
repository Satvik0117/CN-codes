// https://codeforces.com/problemset/problem/1037/C


#include<bits/stdc++.h>
using namespace std;

void flip(char &c){
	if(c==0)c=1;
	if(c==1)c=0;
}

int main(){
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	int cost=0;
	// for(int i=0;i<n;i++){
	// 	if(t[i]!=s[i]){
	// 		if(i+1<=n-1 && s[i+1]!=t[i+1]&& s[i+1]!=s[i]){	//Note 1st condition
	// 			swap(s[i],s[i+1]);

	// 		}
	// 		else{
	// 			flip(s[i]);
	// 		}
	// 			cost+=1;
	// 	}
	// }
	//dont need to actually flip/swap they just want the cost NOTE the increament in i
	for(int i=0;i<n;){
		if(t[i]!=s[i]){
			if(i+1<=n-1 && s[i+1]!=t[i+1]&& s[i+1]!=s[i]){	//Note 1st condition
				// swap(s[i],s[i+1]);
				i+=2;
			}
			else{
				//flip(s[i]);
				i++;
			}
				cost+=1;
		}
	}
cout<<cost;

}