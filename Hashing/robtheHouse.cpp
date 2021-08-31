#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int RobTheHouse(vector<int> &v,int n){
	if(n == 0){
		return v[0];
	}
	if(n == 1){
		return max(v[0],v[1]);
	}
	if(dp[n]!= -1)
		return dp[n];
	return dp[n] = max(RobTheHouse(v,n-2)+v[n],RobTheHouse(v,n-1));
}
int RobTheHouse_itr(vector<int> &v){
	dp[0] =  v[0];
	dp[1] = max(v[1],v[0]);
	int n = v.size();
	for(int i=2;i<n;i++){
		dp[i] = max(dp[i-2]+v[i],dp[i-1]);
	}
	return dp[n-1];
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}	
	cout<<RobTheHouse_itr(v)<<"\n";
	return 0;
}