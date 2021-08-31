#include<bits/stdc++.h>
using namespace std;
int dp[10000];
int min_coins(int coins[],int sum){
	if(sum == 0)
		return 0;
	if(dp[sum]!=0)
		return dp[sum];
	int n = sizeof(coins)/sizeof(int);
	int ans = INT_MAX;
	for(int i =0;i<n;i++){
		if(sum - coins[i]>=0){
			int sub = min_coins(coins,sum-coins[i]);
			ans = min(ans,sub+1);
		}
	}
	return dp[sum] = ans;
}
int min_coins_itr(int coins[],int sum){
	int T = sizeof(coins)/sizeof(int);
	for(int n = sum;n<=sum;n++){
		dp[n] = INT_MAX;
		for(int i = 0;i<T;i++){
			if(n-coins[i]>=0){
				dp[n] = max(dp[n],dp[n-coins[i]]+1)
			}
		}
	}
	return dp[sum];
}
int main(){
	int coins[] = {};
	int sum = ;
	cout<<min_coins(coins,sum)<<endl;
	return 0;
}