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

int count;
int vis[100005];
pii dfs(int src){
	vis[src] = true;
	int subred = 0;
	int subblue = 0;
	if(color[src] == 'A')
		subred++;
	else if(color[src] == 'B')
		subblue++;

	for(auto ch : g[src]){
		if(!vis[src]){
			pii sub = dfs(ch);
			count += (sub.ff == red and sub.ss == 0);
			count += (sub.ff == 0 and sub.ss == blue);
			subred += sub.ff;
			subblue += sub.ss;
		}
	}
	return {subred,subblue};
}

vector<int> g[100005];
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n; 
    vector<char> colors(n);
    for(int  i=0;i<n;i++){
    	char color;
    	int red = 0,blue = 0;
    	cin >> color;
    	colors[i] = color;
    	if(color == 'A'){
    		red += 1;
    	}else if (color == 'B'){
    		blue += 1;
    	}
    }
    for(int i=0;i<n-1;i++){
    	int x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
    dfs(0);
    cout<<count<<"\n";
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