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
 
vi wt,val;
int n,cap;
int dp[1001][1001];
int N_Knapsack(int i,int cap){
	if(i == 0 || cap == 0)
		return 0;
	if(dp[i][cap] != -1)
		return dp[i][cap];
	if(wt[i] > cap){
		return dp[i][cap] = N_Knapsack(i-1,cap);
	}else{
		return dp[i][cap] = max(val[i]+N_Knapsack(n,cap-wt[i]),N_Knapsack(i-1,cap));
	}
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    memset(dp,-1,sizeof(dp));
    cin>>n>>cap;
    wt.resize(n);
    val.resize(n);
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
    cout<<N_Knapsack(n-1,cap)<<"\n";
}
 
int32_t main()
{
    c_p_c();
    return 0;
}