#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int n;
vector<vector<int> > dp(n,vector<int>(n,0));

helper(vector<int>&piles,vector<int>&dp,int i,int m){
	if(i == n)
		return 0;
	if(2*m >= n-i)
		return sum[i];

	if(dp[i][m])
		return dp[i][m];

	int res = INT_MAX;
	for(int j = 1;j<= 2*m;j++){
		res = min(res,helper(piles,dp,i+j,max(j,m)));
	}

	return dp[i][m] = sum[i] - res;
}
int stoneII(){
	 n = piles.size();
	if(n == 0)
		return 0;

	vector<int> sum(n+1,0);
	for(int i = n-1;i>=0;i--)
		sum[i] = sum[i+1] + piles[i];

	helper(piles,dp,0,1);
	return dp[0][1];

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    memset(dp,-1,sizeof dp);
    n = A.size();
    cout<<func(0,1)<<"\n";
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
    return 0;
}