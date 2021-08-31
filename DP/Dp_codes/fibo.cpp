#include<bits/stdc++.h>
using namespace std;
int fibo(int n,int dp[]){
	if(n == 1 || n == 0)
		return n;
	if(dp[n]!=0){
		return dp[n];
	}
	int ans = fibo(n-1,dp) + fibo(n-2,dp);
	return dp[n] = ans;

}
int fibBU(int n){
	int dp[100]={0};
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
int fibspaceOpt(int n){
	if(n == 0 || n == 1)
		return n;
	int a=0;
	int b=1;
	int c;
	for(int i=2;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
int main(){
			 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
   			freopen("output.txt", "w", stdout);
			#endif

	int dp[100]={0};
	int n;
	cin>>n;
	cout<<fibo(n,dp)<<endl;
	return 0;
}