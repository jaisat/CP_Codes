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
 
string a,b,c;
int dp[205][205][205];
int LCS3(int i,int j,int k){
	if(i == a.size() || j == b.size() || k == c.size()){
		return 0;
	}
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	if(a[i] == b[j] and b[j] == c[k]){
		return dp[i][j][k] = 1 + LCS3(i+1,j+1,k+1);
	}
	/*if(a[i] == b[j]){
		return  dp[i][j][k] = LCS3(i,j,k+1);
	}
	if(b[j] == c[k]){
		return dp[i][j][k] = LCS3(i+1,j,k);
	}
	if(c[k] == a[i]){
		return dp[i][j][k] = LCS3(i,j+1,k);
	}*/
	return dp[i][j][k] = max({LCS3(i+1,j,k),LCS3(i,j+1,k),LCS3(i,j,k+1)});
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    memset(dp,-1,sizeof(dp));
    cin >> a >> b >> c;
    cout<<LCS3(0,0,0);
}
 
int32_t main()
{
    c_p_c();
    return 0;
}