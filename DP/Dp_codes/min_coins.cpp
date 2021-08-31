#include<bits/stdc++.h>
using namespace std;
int min_coins(int n,int coins[],int T,int dp[]){
	if(n == 0)
		return 0;
	if(dp[n]!=0)
		return dp[n];
	int ans = INT_MAX;
	for(int i=0;i<T;i++){
		if(n-coins[i]>=0){
			int sub = min_coins(n-coins[i],coins,T,dp);
			ans = min(ans,sub+1);
		}
	}
	return dp[n] = ans;
}
int min_coinsBU(int N,int coins[],int T){
	int dp[100]={0};
	dp[0] = 0;
	for(n=1;n<=N;n++){
		dp[n] = INT_MAX;
		for(int i=0;i<T;i++){
			if(n-coins[i]>=0){
				int sub = dp[n-coins[i]]+1;
				dp[n] = min(dp[n],sub);
			}
		}
	}
	return dp[N];
}
int main(){
	int dp[100]={0};
	int coins[]={1,3,7};
	int T = sizeof(coins)/sizeof(int);
	int n;
	cin>>n;
	cout<<min_coins(n,coins,T,dp);
	return 0;
}