#include<bits/stdc++.h>
using namespace std;
bool check_sum(int arr[],int n){
	int pre = 0;
	unordered_set<int> s;
	for(int i =0;i<n;i++){
		pre += arr[i];
		if(pre == 0 or s.find(pre)!=s.end()){
			return true;
		}
		s.insert(pre);
	}
	return false;
}
int  main(){

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<check_sum(arr,n)<<endl;
	return 0;
}