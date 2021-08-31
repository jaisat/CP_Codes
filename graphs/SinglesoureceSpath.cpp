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

vector<vector<int> > g;
int N;
void addEdge(int u,int v){
	g[u].pb(v);
	g[v].pb(u);
}
void sssp(int src,int dest){
	vector<int> parent(N,-1);
	vector<int> dist(N,INT_MAX);

	queue<int> Q;
	Q.push(src);
	dist[src] = 0;
	while(!Q.empty()){
		int nbr = Q.front();
		Q.pop();

		for(auto nbrs : g[nbr]){
			if(dist[nbrs] == INT_MAX){
				dist[nbrs] = dist[nbr] + 1;
				parent[nbrs] = nbr;
				Q.push(nbrs);
			}
		}
	}

	cout<<dist[dest]<<"\n";
	while(dest != -1){
		cout<<dest<<"--> ";
		dest = parent[dest];
	}
}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    N = 6;

    g.reserve(7);
    addEdge(0,1);
    addEdge(1,2);
    addEdge(0,3);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(4,5);
    addEdge(4,6);
    addEdge(5,6);

    sssp(0,5);
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