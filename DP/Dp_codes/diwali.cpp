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
#define mod             1000003
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int dp[105][2][105];
int func(int n,int prev,int k){
	if(n == 0){
		if(k == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if(dp[n][prev][k] != -1)
		return dp[n][prev][k];

	int op1 = func(n-1,0,k);
	int op2;
	if(prev){
		op2 = func(n-1,1,k-1);
	}else{
		op2 = func(n-1,1,k);
	}
	return dp[n][prev][k] = (op1 % mod + op2 % mod) % mod;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	memset(dp,-1,sizeof(dp));
    	int n,k;
    	cin >> n >> k;
    	cout<<((func(n-1,0,k)%mod + func(n-1,1,k)%mod)%mod)<<"\n";
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}