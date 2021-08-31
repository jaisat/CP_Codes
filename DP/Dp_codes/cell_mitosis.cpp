#include<bits/stdc++.h>
using namespace std;
long long solveCell(int n,int x,int y,int z){
	long long  dp[100]={0};
	dp[0]=0;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i&1){
			dp[i] = min(dp[i-1]+y,dp[(i+1)/2]+x+z);
		}
		else{
			dp[i] = min(dp[i/2]+x,dp[i-1]+y);	
		}
	}
	return dp[n];
}
int main(){
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	cout<<solveCell(n,x,y,z)<<endl;
	return 0;
}