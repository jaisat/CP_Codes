#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
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
 
vector<vector<pii > > dp;
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vi> v {};
    int n = v.size();
    int m = v[0].size();
   	dp.resize(n+1,vector<pii>(m+1,{0,0}));
   	dp[0][0] = {v[0][0],v[0][0]};

   	for(int i=1;i<m;i++){
   		int s = dp[0][i-1].ss + v[0][i]; 
   		int f = min(dp[0][i-1].ff,s);
   		dp[0][i] = {f,s};
   	}

   	for(int i=1;i<n;i++){
   		int s = dp[i-1][0].ss + v[i][0]; 
   		int f = min(dp[i-1][0].ff,s);
   		dp[i][0] = {f,s};
   	}
   	for(int i=1;i<n;i++){
   		for(int j=1;j<m;j++){
   			int s1 = dp[i-1][j].ss + v[i][j];
   			int f1 = min(dp[i-1][j].ff,s1); 
   			int s2 = dp[i][j-1].ss + v[i][j];
   			int f2 = min(dp[i][j-1].ff,s2);
   			if(f1 > f2){
   				dp[i][j] = {f1,s1};
   			}else{
   				dp[i][j] = {f2,s2};
   			}
   		}
   	}
   	cout<<dp[n-1][m-1].ff + 1;
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