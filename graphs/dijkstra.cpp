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

const int INF = 1e9;
 
vector<pair<int,int> > g[10005];
int dist[10005];

void Dijkstra(int src){
	set<pair<int,int> > s; // {distance,node}
	s.insert({0,src});
	dist[src] = 0;

	while(!s.empty()){
		int dis  = s.begin()->first;
		int node = s.begin()->second;
		s.erase(s.begin());

		for(pair<int,int> nbr : g[node]){
			int newdis = nbr.ss + dis;
			int newver = nbr.ff;
			if(newdis < dist[newver]){
				s.erase({dist[newver],newver});
				dist[newver] = newdis;
				s.insert({dist[newver],newver});
			}
		} 
	}

	for(int i=1;i<=n;i++)
		cout << dist[i] <<" ";
}


void Dijks(int src){
	set<pair<int,int> > s;
	s.insert({0,src});
	dist[src] = 0;

	while(!s.empty()){
		int dis  =  s.begin()->first;
		int node =  s.begin()->second;

		for(auto nbr : g[node]){
			if(dist[nbr.ss] > dist[node] + nbr.ss){
				s.erase(s.find({dist[nbr.ss],nbr.ss}));
				dist[nbr.ss] = dist[node] + nbr.ff;
				s.insert({dist[nbr.ss],nbr.ff});
			}
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
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	int x,y,w;
    	cin >> x >> y >> w;
    	g[x].pb({y,w});
    	g[y].pb({x,w});
    }

    for(int i=1;i<=n;i++)
    	dist[i] = INF;

    Dijkstra(1);

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