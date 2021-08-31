#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
		#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
   			freopen("output1.txt", "w", stdout);
			#endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n,0);
		vector<int> presum(n,0);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		presum[0] = arr[0];
		for(int i=1;i<n;i++){
			presum[i] = arr[i] + presum[i-1];
		}
		vector<vector<int> > dp(n,vector<int>(n,0));
		for(int i=1;i<n;i++){
			int r = 0, c = i;
			while(c < n){
				int sub = 0;
				for(int k=r;k<c;k++){
					int v1 = (r-1)>=0?presum[r-1]:0;
					int v2 = k>=0?presum[k]:0;
					if(presum[k] - v1 == presum[c] - v2){
						sub = 1 + max(dp[r][k],dp[k+1][c]);
						break;
					}
				}
				dp[r][c] = sub;
				c++,r++;
			}
		}
		cout<<dp[0][n-1]<<"\n";
	}
	return 0;
}