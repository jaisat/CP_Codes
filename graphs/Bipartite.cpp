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
 
vector<int> g[100005];
int vis[100005];
int odd_cycle;
void dfs(int src,int par,int col){
	vis[src] = col;
	for(auto nbr : g[src]){
		if(vis[nbr] == 0){
			dfs(nbr,src,3 - col);
		}else if (nbr != par && vis[nbr] == col){
			// backedge 
			odd_cycle = 1;
		}
	}
	return;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m,x,y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    dfs(1,-1,1);
    if(odd_cycle)
    	cout<<"Not Bipertite"<<"\n";
    else
    	cout<<"Yes";
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