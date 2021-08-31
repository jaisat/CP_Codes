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
 
string s,t;
int n,m,k;
int dp[1005][1005][12][2];
int solve(int is,int it,int rem,int cont){
	if(is == n or it == m){
		return ((rem == 0)?0:INT_MIN);
	}
	if(rem == 0)
		return 0;
	if(dp[is][it][rem][cont] != -1)
		return dp[is][it][rem][cont];
	int ret = INT_MIN;
		ret = max(ret,solve(is+1,it,rem-cont,0));
		ret = max(ret,solve(is,it+1,rem-cont,0));
		if(s[is] == t[it]){
			ret = max(ret,1 + solve(is+1,it+1,rem,1));
			ret = max(ret,1 + solve(is+1,it+1,rem-1,0));
		}
		return dp[is][it][rem][cont] = ret;		
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(dp,-1,sizeof(dp));
    cin >> n >> m >>k;
    cin >> s >> t;
    cout<<solve(0,0,k,0)<<"\n";
}
 
int32_t main()
{
    c_p_c();
    return 0;
}