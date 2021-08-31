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
 
const int N = 1e5+2;
int dp[N][4];
int n;
vector<vector<int> > adj{N};
int dfs(int i,int xo,int par){
	if(i == n){
		return (xo == 0);
	}
	if(dp[i][xo] != -1){
		return dp[i][xo];
	}
	int ret = 0;
	int ch = 0;
	for(int k=0;k<=3;k++)	{
		int val = 1;
		for(auto it : adj[i]){
			if(it != par){
				ch++;
				val = (val*1LL*dfs(it,xo^k,i)) % mod;
			}
		}
		ret = (ret + val) % mod;
	}
	if(ch == 0){
		ret = 0;
		for(int k=0;k<=3;k++){
			ret = (ret + dfs(n,xo^k,i)) % mod;
		}
		return dp[i][xo] = ret;
	}
	return dp[i][xo] = ret;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	memset(dp,-1,sizeof dp);
    	cin >> n;
    	for(int i=1;i<=n-2;i++){
    		int a,b;
    		cin >> a >> b;
    		adj[a].pb(b);
    		adj[b].pb(a);
    	}
    
    	int ans = 0;
    	for(int k=0;k<=3;k++){
    		ans += dfs(1,k,-1);
    	}
    	ans %= mod;
    	cout<<ans<<"\n";
    	for(int i=1;i<=n;i++){
    		adj[i].clear();
    	}
    }
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