#include<bits/stdc++.h>
using namespace std;
int min_step_one(int n,int dp[]){
	// Base Case
	if(n == 1)
		return 0;
	if(dp[n]!=0)
		return dp[n];

	int op1,op2,op3;
	op1=op2=op3=INT_MAX;

	if(n % 3 == 0)
		op1 = min_step_one(n/3,dp)+1;
	if(n % 2 == 0)
		op2 = min_step_one(n/2,dp)+1;
	op3 = min_step_one(n-1,dp)+1;

	int ans = min(min(op1,op2),op3);
	return dp[n] = ans;
}
int main(){
		 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
   			freopen("output1.txt", "w", stdout);
			#endif	
	int dp[100]={0};
	int n;
	cin>>n;
	cout<<min_step_one(n,dp);
	return 0;
}