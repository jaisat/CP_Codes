#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int* countFlowers(int k){
	int* dp = new int[100005];
	dp[0] = 1;
	for(int i=1;i<=100000;i++){
		if(i<k){
			dp[i] = dp[i-1];
		}else{
			dp[i] = (dp[i-1]%mod + dp[i-k]%mod)%mod;
		}
	}
	for(int i=1;i<=100000;i++){
		dp[i] = (dp[i-1]%mod + dp[i]%mod)%mod;
	}
	return dp;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t,k;
	cin>>t>>k;
	int *dp = countFlowers(k);
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<((dp[b] - dp[a-1] + mod)%mod)<<"\n";
	}
	return 0;
}