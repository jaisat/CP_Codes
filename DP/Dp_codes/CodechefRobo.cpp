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
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m,n,p;
    cin >> m >> n >> p;
    vector<vector<int> > grid(m,vector<int>(n,1));
    vector<vector<int> > dp(m,vector<int>(n,0));
    while(p--){
    	int x,y;
    	cin >> x >> y;
    	grid[x-1][y-1] = 0;
    }
   	if(grid[m-1][n-1] == 1) dp[m-1][n-1] = 1;
   	for(int i = m-2;i>=0;i--){
   		if(grid[i][n-1] == 0) dp[i][n-1] = 0;
   		else dp[i][n-1] += dp[i+1][n-1];
   	}
   	for(int i=n-2;i>=0;i--){
   		if(grid[m-1][i] == 0) dp[m-1][i] = 0;
   		else dp[m-1][i] += dp[m-1][i+1];
   	}
   	for(int i=m-2;i>=0;i--){
   		for(int j=n-2;j>=0;j--){
   			if(grid[i][j] == 0) dp[i][j] = 0;
   			else dp[i][j] += (dp[i+1][j] % mod + dp[i][j+1] % mod) % mod;
   		}
   	}
   	cout<<dp[0][0]<<"\n";
}
 
int32_t main()
{
    c_p_c();
    return 0;
}