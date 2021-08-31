#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int cnt_sub_diff(int a[],int sum,int n){
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(dp[n][sum] != -1)
		return dp[n][sum];
	if(a[n-1]<=sum){
		return dp[n][sum] = cnt_sub_diff(a,sum-a[n-1],n-1) + cnt_sub_diff(a,sum,n-1);
	}else{
		return dp[n][sum] = cnt_sub_diff(a,sum,n-1);
	}
}
int main(){
	memset(dp,-1,sizeof(dp));
	int a[] = {1,1,2,3}
	int n = sizeof(a)/sizeof(int);
	int d = 1;
	int sum = 0;
	for(int i = 0;i<n;i++){
		sum += a[i];
	}
	cout<<cnt_sub_diff(a,(sum+d)/2,n)<<endl;
	return 0;
}