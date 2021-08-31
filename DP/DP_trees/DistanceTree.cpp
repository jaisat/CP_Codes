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
 
vector<int> g[50001];
int dp1[50001][501],dp2[50001][501];

void dfs(int src,int par,int k){
	for(auto ch : g[src]){
		if(ch != par){
			dfs(ch,src,k);
		}
	}
	dp1[src][0] = 1;
	for(int distance = 1;distance<=k;distance++){
		dp1[src][distance] = 0;
		for(auto ch : g[src]){
			if(ch != par){
				dp1[src][distance] += dp1[ch][distance-1];
			}
		}
	}
}

void solve(int src,int par,int k){
	for(int i=0;i<=k;i++)
		dp2[src][i] = dp1[src][i];

	if(par != 0){
		dp2[src][1] += dp2[src][0];
		for(int dis=2;dis<=k;dis++){
			dp2[src][dis] += dp2[par][dis-1];
			dp2[src][dis] -= dp1[src][dis-2];
		}
	}

	for(auto ch : g[src]){
		if(ch != par){
			solve(ch,src,k);
		}
	}
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    dfs(1,0,k);
    solve(1,0,k);
    int ans = 0;
    for(int i=1;i<=n;i++)
    	ans += dp2[i][k]	;

    cout<<ans/2<<"\n";
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