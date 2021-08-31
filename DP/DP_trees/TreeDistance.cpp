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

int depth[200001];
int ans[200001];
vector<int> g[200001];

void depth_tree(int src,int par){
	int max_depth = 0;
	for(auto ch : g[src]){
		if(ch != par){
			depth_tree(ch,src);
			max_depth = max(max_depth,1 + depth[ch]);
		}	
	}
	depth[src] =  max_depth;
}

void solve(int src,int par,int par_ans){
	vi pre_max,suff_max;
	for(auto ch : g[src]){
		if(ch != par){
			pre_max.pb(depth[ch]);
			suff_max.pb(depth[ch]);
		}
	}

	for(int i=1;i<pre_max.size();i++)
		pre_max[i] = max(pre_max[i],pre_max[i-1]);
	for(int i=suff_max.size()-2;i>=0;i--)
		suff_max[i] = max(suff_max[i],suff_max[i+1]);

	int c_no = 0;
	for(auto ch : g[src]){
		if(ch != par){
				int op1 = (c_no == 0) ? INT_MIN : pre_max[c_no-1];
				int op2 = (c_no == suff_max.size() - 1) ? INT_MIN : suff_max[c_no+1];
				int parent_ans = 1 + max({par_ans,op1,op2});

				solve(ch,src,parent_ans);
				c_no++;
		}
	}

	ans[src] = 1 + max(pre_max.empty() ? -1 : pre_max.back(),par_ans);
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
    depth_tree(1,0);
    solve(1,0,-1);
    for(int i=1;i<=n;i++)
    	cout<<ans[i]<<" ";
}
 
int32_t main()
{
    //clock_t begin = clock();
    c_p_c();
	/*#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif */
    return 0;
}