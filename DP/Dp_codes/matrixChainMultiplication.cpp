#include<bits/stdc++.h>
#define int long long int
using namespace std;
int dp[200][200];
int MatrixChain(vector<int> &A){
	int n = A.size()-1;
	memset(dp,0,sizeof dp);
	for(int i = 1;i < n; i++){
		int r = 0, c = i;
		while(c < n){
			int ans = INT_MAX;
			for(int pivot=r;pivot<c;pivot++){
				ans = min(ans,dp[r][pivot]+dp[pivot+1][c]+A[r]*A[pivot+1]*A[c+1]);
			}
			dp[r][c] = ans;
			r++,c++;
		}
	}
	return dp[0][n-1];
}
signed main(){
		#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
   			freopen("output.txt", "w", stdout);
		#endif
	vector<int> A;
	int n;
	cin>>n;
	A.resize(n);
	for(int i = 0; i < n; i++)
		cin>>A[i];
	cout<<MatrixChain(A)<<"\n";

	return 0;
}