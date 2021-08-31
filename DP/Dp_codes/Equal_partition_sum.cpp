#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
bool Equal_partition(int a[],int sum,int n){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(a[n-1]<=sum){
        return dp[n][sum] = Equal_partition(a,sum-a[n-1],n-1) || Equal_partition(a,sum,n-1);
    }else{
        return dp[n][sum] = Equal_partition(a,sum,n-1);
    }
}
int main(){
	int a[] = {1,5,3};
	int sum = 0;
    memset(dp,-1,sizeof(dp));
	int n = sizeof(a)/sizeof(int);
	for(int i = 0;i<n;i++)
		sum += a[i];
    if(sum &1)
        cout<<0<<endl;
    else
	cout<<Equal_partition(a,sum/2,n)<<endl;
	return 0;
}