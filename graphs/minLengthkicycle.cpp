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

void bfs(int src,int n,int &ans){
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
				int sub = dist[ch] + dist[curr] + 1;
				cout<<sub<<" ";
				ans = min(ans,sub);
				
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
    int ans = n + 1;
    for(int i=1;i<=n;i++){
    	bfs(i,n,ans);
    	cout<<"\n";
    }
    if(ans == n + 1)
    	cout<<"No Cycle";
    else
    	cout<<"\n"<<ans<<"\n";
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