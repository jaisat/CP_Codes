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
 
vector<vector<int> > graph;

vi bfs(int src,int c){
	queue<int> Q;
	vi dist(n+1,-1);
	dist[src] = 0;
	Q.push(src);
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		for(auto nbr : graph[node]){
			if(dist[nbr] != -1 or nbr.ss != c)
				continue;
			Q.push(nbr.ff);
			dist[nbr.ff] = dist[node] + 1;
		}
	}
	return dist;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    graph.reserve(n+1);
    while(m--){
    	int x,y,c;
    	cin >> x >> y >> c;
    	graph[x].pb({y,c});
    	graph[y].pb({x,c}); 
    }
    int src,dest;
    cin >> src >> dest;
    vi ds = bfs(src,0,n);
    vi dd = bfs(dest,1,n);
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
    	if(i == src || i == dest || ds[i] == -1 || dd[i] == -1 || dd[dest] == -1)
    		continue;

    	ans = min(ans,ds[i]+dd[i]);
    }
    if(ans == INT_MAX) ans = -1;
    cout<<ans<<"\n";
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