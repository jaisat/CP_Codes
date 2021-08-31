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
vector<vi> cost;
vector<vi> dp;
int MinCostPath(int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i == 0 and j == 0){
				dp[i][j] = cost[i][j];
			}else if( i == 0){
				dp[i][j] = cost[i][j] + dp[i][j-1];
			}else if ( j== 0){
				dp[i][j] = cost[i][j] + dp[i-1][j];
			}else{
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + cost[i][j];
 			}
		}
	}
	return dp[r-1][c-1];
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int r,c;
    cin>>r>>c;
    cost.resize(r,vi(c));
    dp.resize(r,vi(c));
    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++)
    		cin >> cost[i][j];
    }
    cout<<MinCostPath(r,c)<< "\n";
}
 
int32_t main()
{
    c_p_c();
    return 0;
}