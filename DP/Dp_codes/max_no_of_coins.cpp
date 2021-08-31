#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int dp1[100000];
int max_no_coins(int coins[],int sum,int n){
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp[n][sum]!=-1)
		return dp[n][sum];
	if(sum-coins[n-1]>=0){
		return dp[n][sum] = max_no_coins(coins,sum-coins[n-1],n) + max_no_coins(coins,sum,n-1);
	}else{
		return dp[n][sum] = max_no_coins(coins,sum,n-1);
	}
}
int max_no_coins_iter(int coins[],int sum,int n){
	for(int i = 0;i<=n;i++){
		dp[i][0] = 1;
	}
	for(int i = 1;i<=sum;i++)
		dp[0][i] = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=sum;j++){
			if(j- coins[i-1]>=0){
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}
int maxNo(int coins[],int sum){
	if(sum == 0)
		return 0;
    if(dp[sum]!=0)
        return dp[sum];
	int n = sizeof(coins)/sizeof(int);
    int ma = INT_MIN;
	for(int i = 0;i<n;i++){
			if(sum - coins[i]>=0){
				int sub =  maxNo(coins,sum-coins[i]);
                ma = max(ma,sub);
			}
	}
	return dp[sum] = ma+1;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int sum = 5; 
	int coins[] = {1,2,3};
	int n =sizeof(coins)/sizeof(int);
	cout<<max_no_coins(coins,sum,n)<<endl;
	return 0;
}