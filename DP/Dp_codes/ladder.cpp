#include<bits/stdc++.h>
using namespace std;
int Ladder(int n,int k,int dp[]){
	if(n==0)
		return 1;
	if(dp[n]!=0)
		return dp[n];
	int sum = 0;
	for(int i=1;i<=k;i++){
		if(n-i>=0)
		sum+=Ladder(n-i,k,dp);
	}
	return dp[n]=sum;
}
// O(N*K)
int LadderBU(int n,int k){
	int dp[100]={0};
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
		if(i-j>=0)
		dp[i]+=	dp[i-j];
	}
	return dp[n];

}

// Optimized Approach O(n+k)
int LadderBU_opt(int n,int k){
	int dp[100]={0};
	dp[0]=dp[1]=1;
	for(int i=2;i<=k;i++){
		dp[i]=2*dp[i-1];
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=2*dp[i-1]-dp[n-k-1];
	}

	return dp[n];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
    		freopen("output1.txt", "w", stdout);
			#endif
	int n,k;
	int dp[100]={0};
	cin>>n>>k;
	cout<<Ladder(n,k,dp)<<endl<<LadderBU(n,k);
	return 0;
}