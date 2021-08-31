#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int unbounded_knapsack(int val[],int wt[],int W,int n){
	if(n == 0 || W == 0)
		return 0;
	if(dp[n][W]!=0)
		return dp[n][W];
	if(W>=wt[n-1]){
		return dp[n][W] = max(val[n-1]+unbounded_knapsack(val,wt,W-wt[n-1],n),unbounded_knapsack(val,wt,W,n-1));

	}else{
		return dp[n][W] = unbounded_knapsack(val,wt,W,n-1);
	}
}
int unbounded_knapsack_iterative(int val[],int wt[],int W,int n){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=W;j++){
			if(j>=wt[i-1]){
				dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}
int main(){
	int val[] = {};
	int wt[] = {};
	int W =  ;
	int n = sizeof(val)/sizeof(int);
	cout<<unbounded_knapsack(val,wt,W,n)<<endl;
	return 0;

}