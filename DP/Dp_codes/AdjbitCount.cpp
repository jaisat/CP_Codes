#include<bits/stdc++.h>
#define int long long int
using namespace std;
int dp[105][105][2];
int adjBc(int n,int k,int f){
	if(n == 0) return 0;
	if(n == 1){
		if(k == 0) return 1;
		else return 0;
	}
	if(dp[n][k][f]!=-1) return dp[n][k][f];
	int retval = -1;
	if(f == 1){
		retval = adjBc(n-1,k-1,1) + adjBc(n-1,k,0);
	}else{
		retval = adjBc(n-1,k,0) + adjBc(n-1,k,1);
	}
	return dp[n][k][f] = retval;
}
signed main(){
		#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
   			freopen("output1.txt", "w", stdout);
		#endif
	int t;
	cin>>t;
	while(t--){
		int num,n,k;
		cin>>num>>n>>k;
		memset(dp,-1,sizeof(dp));
		int ans = adjBc(n,k,0);
		ans += adjBc(n,k,1);
		cout<<num<<" "<<ans<<"\n";
	}
	return 0;
}