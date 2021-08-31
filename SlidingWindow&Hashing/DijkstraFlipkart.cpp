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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int> > > g(n);
    for(int i=0;i<m;i++){
    	int x,y,w;
    	cin >> x >> y >> w;
    	x--;
    	y--;
    	g[x].pb({y,w});
    	g[y].pb({x,w});
    }

    vector<vector<int> > dp(n,vector<int>(k+1,INT_MAX));
    int s = 0;
    for(int i=0;i<=k;i++)
    	dp[s][i] = 0;

    set<pair<int,pair<int,int> > >  pq;
    pq.insert({0,{s,0}});

    while(!pq.empty()){
    	int u = (pq.begin()->second).first;
    	int j = (pq.begin()->second).second;

    	pq.erase(pq.begin());

    	for(int i=0;i<g[u].size();i++){
    		int v = g[u][i].first;
    		int w = g[u][i].second;

    		if(dp[v][j] > dp[u][j] + w ){
    			pq.erase({dp[v][j],{v,j}});
    			dp[v][j] = dp[u][j] + w;
    			pq.insert({dp[v][j],{v,j}});
    		}

    		if(j != k and dp[v][j+1] > dp[u][j]){
    			pq.erase({dp[v][j+1],{v,j+1}});
    			dp[v][j+1] = dp[u][j];
    			pq.insert({dp[v][j+1],{v,j+1}});
    		}
    	}
    }

    for(int i=0;i<n;i++){
    	int ans = dp[i][0];
    	for(int j=1;j<=k;j++){
    		ans = min(ans,dp[i][j]);
    	}
    	cout<<ans<<" ";
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