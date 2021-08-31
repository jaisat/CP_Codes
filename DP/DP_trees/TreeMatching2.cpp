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
 
int subtreeAns[200001];
int subtreeSize[200001];
int ans[200001];
vector<int> g[200001];
void preprocess(int src,int par){
	int numofnodes = 1;
	int ansForsubtree = 0;
	for(auto ch : g[src]){
		if(ch != par){
			preprocess(ch,src);
			numofnodes += subtreeSize[ch];
			ansForsubtree += subtreeAns[ch] + subtreeSize[ch];
		}
	}
	subtreeSize[src] = numofnodes;
	subtreeAns[src] = ansForsubtree;
}

void solve(int src,int par,int par_ans,int total_nodes){
	ans[src] = subtreeAns[src] + par_ans + total_nodes - subtreeSize[src];

	for(auto ch : g[src]){
		if(ch != par){
			solve(ch,src,ans[src] - (subtreeAns[ch] + subtreeSize[ch]),total_nodes);
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
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    preprocess(1,-1);
    solve(1,-1,0,n);
    for(int i=1;i<=n;i++)
    	cout<<ans[i]<<" ";
 
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