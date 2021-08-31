#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int cnt_subset_sum(int a[],int sum,int n){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(a[n-1]<=sum){
        return dp[n][sum] = cnt_subset_sum(a,sum-a[n-1],n-1) + cnt_subset_sum(a,sum,n-1);
    }else{
        return dp[n][sum] = cnt_subset_sum(a,sum,n-1);
    }
}
int cnt_subset_sum_iterative(int a[],int sum,int n){
    for(int i = 0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i = 1;i<=sum;i++)
        dp[0][i] = 0;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j- a[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    memset(dp,-1,sizeof(dp));
    int a[] = {2,3,5,6,8,10};
    int n = sizeof(a)/sizeof(int);
    int sum;
    cin>>sum;
    cout<< cnt_subset_sum(a,sum,n)<<endl;
    cout<< cnt_subset_sum_iterative(a,sum,n)<<endl;
    return 0;
}