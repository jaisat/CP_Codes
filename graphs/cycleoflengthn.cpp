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
 
vector<int> g[10005];
int cnt;
void bfs(int src,int n){
	vector<int> dist(n+1,INT_MAX);
	queue<int> Q;
	Q.push(src);
	dist[src] = 0;
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();

		for(auto ch : g[curr]){
			if(dist[ch] == INT_MAX){
				dist[ch] = dist[curr] + 1;
				Q.push(ch);
			}else if(dist[ch] >= dist[curr]){
				if((dist[ch] + dist[curr] + 1 ) == 4)
					cnt++;
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
    int n,m,x,y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
   
    for(int i=0;i<n;i++){
    	bfs(i,n);
  
    }
   cout<<cnt<<"\n";
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