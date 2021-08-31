#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main(){
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
   			freopen("output1.txt", "w", stdout);
			#endif
		int n;
		cin>>n;
		vi arr(n);
		vector<vector<int> > dp(n,vector<int>(n,0));
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i = 0;i<n;i++){
			int r = 0, c = i;
			while(c < n){
				int x = (r+2<=c)?dp[r+2][c]:0;
				int y = (r+1<=c-1)?dp[r+1][c-1]:0;
				int z = (r<=c-2)?dp[r][c-2]:0;

				dp[r][c] = max(arr[r] + min(x,y),arr[c]+ min(y,z));
				c++,r++;
			}
		}
		cout<<dp[0][n-1]<<"\n";
		return 0;
}