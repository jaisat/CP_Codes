#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100][100];
vector<int> arr;
int Func(int id,int prev){
	if(id == n){
		return 0;
	}
	if(dp[id][prev] != -1)
		return dp[id][prev];

	int ans = 0;
	ans = max(ans,Func(id+1,prev));
	if(arr[id] > prev){
		ans = max(ans,1 + Func(id+1,arr[id]));
	}
	return dp[id][prev] = ans;

}
int main(){
	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
   			freopen("output.txt", "w", stdout);
	#endif
	memset(dp,-1,sizeof(dp));
	cin >> n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<Func(0,0)<<"\n";

/* <------------COOL TRICK----------> */

	set<int> s;
	for(auto x : arr){
		auto it = s.lower_bound(x);
		if(it!=s.end()){
			s.erase(it);
		}
		s.insert(x);
	}
	cout<<(int)s.size()<<"\n";
	return 0;
}