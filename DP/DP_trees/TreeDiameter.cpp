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
int downpaths[200001];
int dia[200001];
void eva_dia(int src,int par){
	bool leaf = 1;
	int max_down = 0;
	for(auto child : g[src]){
		if(child != par){
			leaf = 0;
			eva_dia(child,src);
			max_down = max(max_down,downpaths[child]);
		}
	}
	if(leaf) downpaths[src] = 0;
	else downpaths[src] = 1 + max_down;
}

void solve(int src,int par){
	int ans = 0;    
	vi childDownpaths;
	for(auto child : g[src]){
		if(child != par){
			solve(child,src);
			childDownpaths.pb(downpaths[child]);
			ans = max(ans,dia[child]);
		}
	}

	sort(childDownpaths.begin(),childDownpaths.end());
	int n1 = childDownpaths.size();
 
	if(n1 == 0) dia[src] = 0;
	else if(n1 == 1) dia[src] = 1 + childDownpaths[0];
	else dia[src] = 2 + childDownpaths[n1-1] + childDownpaths[n1-2];

	dia[src] = max(dia[src],ans);

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    eva_dia(1,-1);
    solve(1,-1);

    cout<<dia[1]<<"\n";

}
 
int32_t main()
{
   // clock_t begin = clock();
    c_p_c();
/*	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif */
    return 0;
}