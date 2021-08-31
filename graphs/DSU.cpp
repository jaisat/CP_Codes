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
 int n,m;

int find(int i,vi &parent){
	if(parent[i] == -1)
		return i;
	return parent[i] = find(parent[i],parent);
}

void union_set(int x,int y,vi &parent){
	int s1 = find(x,parent);
	int s2 = find(y,parent);

	if(s1 != s2){
		parent[s1] = s2;
	}
}
/*
bool isCycle(){
	vi parent(n,-1);

	for(auto e : edge){
		int i = e.ff;
		int j = e.ss;

		int s1 = find(i,parent);
		int s2 = find(j,parent);
		if(s1 != s2){
			union_set(i,j,parent);
		}else{
			return true;
		}
	}

	return false;
}*/

bool containsCycle(){
	vi parent(n+1,-1);

	for(int i=1;i<=n;i++){
		for(auto j : g[i]){
			if(j < i)
				continue;

			int s1 = find(i,parent);
			int s2 = find(j,parent);

			if(s1 != s2){
				union_set(i,j,parent);
			}else{
				return true;
			}
		}
	}
	return false;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	int x,y;
    	cin >> x >> y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    cout<<containsCycle()<<"\n";
   	
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