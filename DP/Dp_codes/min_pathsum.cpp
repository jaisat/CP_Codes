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
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vi> grid{{1,3,1},
    {1,5,1},
    {4,2,1}
    };
    vector<vi> dp;
    int m = grid.size();
    int n = grid[0].size();

    dp.resize(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];
    for(int i = 1;i<n;i++){
    	dp[0][i] = grid[0][i] + dp[0][i-1];
    }
    for(int i=1;i<m;i++){
    	dp[i][0] = grid[i][0] + dp[i-1][0];
    }

    for(int i=1;i<m;i++){
    	for(int j=1;j<n;j++){
    		dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
    	}
    }

   /* for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<"\n";
    }*/
    cout<<dp[m-1][n-1]<<"\n";

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