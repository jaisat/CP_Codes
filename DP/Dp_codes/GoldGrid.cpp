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
    int n,m;
    cin >> n >> m;
    vector<vi> grid(n,vi(n,0));
    while(m--){
    	int x,y;
    	cin >> x >> y;
    	grid[x-1][y-1] = 1;
    }
   /* for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<grid[i][j]<<" ";
    	}
    	cout<<endl;
    }*/
    vector<vi> dp(n+1,vi(n+1,0));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i-1][j-1];
    	}
    }
  /*  cout<<endl;
     for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<endl;
    }*/
    int res = INT_MIN;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		int op1 = dp[i][j];
    		int op2 = dp[i][n] - dp[i][j];
    		int op3 = dp[n][j] - dp[i][j];
    		int op4 = dp[n][n] - op1 - op2 - op3;
    		int sub = min(op1,min(op2,min(op3,op4)));
    		res = max(res,sub);
    	}
    }
    cout<<res<<"\n";
}
 
int32_t main()
{
    c_p_c();
    return 0;
}