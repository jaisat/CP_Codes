#include<bits/stdc++.h>
using namespace std;
int longest_Lenght(int arr[],int n){
	int pre = 0;
	int len = 0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;++i){
		pre += arr[i];
		if(pre == 0){
			len = max(len,i+1);
		}
		if(mp.find(pre)!= mp.end()){
			len = max(len,i - mp[pre]);
		}else{
			mp[pre] = i;
		}
	}
	return len;
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i)
		cin>>arr[i];
	cout<<longest_Lenght(arr,n)<<endl;
	return 0;
}