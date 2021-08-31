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
 
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int dp[51][51][51];
int m,n,mx,s,e;
int dfs(int i,int j,int moves){
	if(i < 0 || i >= m || j < 0 || j >= n)
		return 1;
	
	if(moves == 0)
		return 0;

	if(dp[i][j][moves] != -1)
		return dp[i][j][moves];

	int ans = 0;
	for(int k = 0; k < 4; k++){
		int x = i + dx[k];
		int y = j + dy[k];

		ans += dfs(x,y,moves-1);
	}

	return dp[i][j][moves] = ans;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    m = 1;
    n = 3;
    mx = 3;
    s = 0;
    e = 1;
    memset(dp,-1,sizeof dp);
   cout<<dfs(s,e,mx)<<"\n";

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