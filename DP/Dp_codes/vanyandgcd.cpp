#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;
signed main(){
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
   			freopen("output1.txt", "w", stdout);
			#endif
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<vector<int> > dp(n,vector<int>(101,0));
	dp[0][arr[0]] = 1;
	int sum = dp[0][1];
	for(int i=1;i < n;i++){
		for(int j = i-1;j>=0;j--){
			if(arr[j] < arr[i]){
				for(int g = 1;g<=100;g++){
					int new_gcd = __gcd(g,arr[i]);
					dp[i][new_gcd] = (dp[i][new_gcd] + dp[j][g])% mod;
				}
			}
		}
		dp[i][arr[i]] += 1;
		sum = (sum + dp[i][1]) % mod;
	}
	cout<<sum<<"\n";
	return 0;
 } 