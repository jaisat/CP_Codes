#include<bits/stdc++.h>
using namespace std;
bool isPalindromic(string s,int l,int r,bool dp[][1001]){
	if(l == r)
		return dp[l][r]=true;
	if(l>r)
		return true;
	
	if(dp[l][r])
		return true;
	if((s[l]==s[r]) && isPalindromic(s,l+1,r-1,dp))
		return dp[l][r]=true;
	return dp[l][r]=false;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
    		freopen("output1.txt", "w", stdout);
			#endif
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool dp[1001][1001]={false};
	int m;
	cin>>m;
	while(m--){
	int l,r;
	cin>>l>>r;
	if(isPalindromic(s,l-1,r-1,dp))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	}
	return 0;
}