#include<bits/stdc++.h>
using namespace std;
int Longest_subarray_k(int arr[],int n,int k){
	int pre = 0;
	int len = 0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		pre += arr[i];
		if(pre == k){
			len = max(len,i+1);
		}
		if(mp.find(pre -k)!=mp.end()){
			len = max(len,i-mp[pre-k]);
		}else{
			mp[pre] = i;
		}
	}
	return len;
}
int main(){
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>k;
	cout<<Longest_subarray_k(arr,n,k)<<endl;
	return 0;
}