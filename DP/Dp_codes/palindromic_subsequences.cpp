#include<bits/stdc++.h>
using namespace std;
int dp[500][500];
string str;
int Palindromic_subsq(int i,int j){
	if(i == j){
		return 1;
	}
	if(i > j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = 0;
	if(str[i] == str[j]){
		ans += 1 + Palindromic_subsq(i+1,j-1);
	}
	ans += Palindromic_subsq(i+1,j) + Palindromic_subsq(i,j-1) - Palindromic_subsq(i+1,j-1);
	return dp[i][j] = ans;
}
int func(string s){
	int n = s.length();
	for(int len = 1;len<=n;len++){
		for(int i=0;i+len<=n;i++){
			int j = i + len - 1;	
			if(i == j){
				dp[i][j] = 1;
				continue;
			}
			if(s[i] == s[j]){
				dp[i][j] += 1 + dp[i+1][j-1];
			}
			dp[i][j] += dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
	return dp[0][n-1];
}
int main(){
		#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		#endif

	memset(dp,0,sizeof(dp));
	cin >> str;
   //	cout<<Palindromic_subsq(0,n-1)<<"\n";
   	cout<<func(str)<<"\n";
	return 0;
}