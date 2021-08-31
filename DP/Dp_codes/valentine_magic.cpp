#include<bits/stdc++.h>
#define int long long 
int dp[5005][5005];
int n,m;
int a[100000],b[100000];
using namespace std;
int valentine(int i,int j){
		if(i == n)
			return 0;
		if(j == m)
			return INT_MAX;
		if(dp[i][j]!=-1)
			return dp[i][j];
		int op1 = abs(a[i] - b[j]) + valentine(i+1,j+1);
		int op2 = valentine(i,j+1);
		return dp[i][j] = min(op1,op2); 
}
signed main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	for(int i = 0;i<n;i++) cin>>a[i];
	for(int i = 0;i<m;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	cout<<valentine(0,0)<<endl;
	return 0;
}