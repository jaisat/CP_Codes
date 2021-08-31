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
 
vector<int> g[200001];
int lvl[200001];
int up[200001][20];

void dfs(int src,int par,int L){
	lvl[src] = L;
	for(auto ch : g[src]){
		if(ch != par){
			dfs(ch,src,L+1);
		}
	}
}

void BinaryLifting(int src,int par){
	up[src][0] = par;
	for(int i=1;i<20;i++){
		if(up[src][i-1] != -1)
			up[src][i] = up[up[src][i-1]][i-1];
		else
			up[src][i] = -1;
	}

	for(auto ch : g[src]){
		if(ch != par){
			BinaryLifting(ch,src);
		}
	}
}

int LiftNode(int node,int k){
	if(node == -1 || k == 0)
		return node;

	for(int i=20;i>=0;i--){
		if(k >= (1<<i))
			return LiftNode(up[node][i],k - (1<<i));
	}
	return -1;
}

int LCA(int u,int v){
	if(lvl[u] < lvl[v])
		swap(u,v);

	u = LiftNode(u,lvl[u]-lvl[v]);
	if(u == v)
		return u;

	for(int i=19;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return LiftNode(u,1);
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    dfs(1,-1,0);
    BinaryLifting(1,-1);
    while(q--){
    	int u,v;
    	cin >> u >> v;
    	int Lca = LCA(u,v);
    	int ans = lvl[u] + lvl[v] - 2 * lvl[Lca];
    	cout<<ans<<"\n";
    }
}
 
int32_t main()
{
   // clock_t begin = clock();
    c_p_c();
	/*#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif */
    return 0;
}