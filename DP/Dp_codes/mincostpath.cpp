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
 
struct pairs
{
	int i;
	int j;
	string psf;
};

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    vector<vector<int> > grid(n,vi(m));
    
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> grid[i][j];
    	}
    }

    vector<vector<int> > dp(n,vi(m,0));

    dp[n-1][m-1] = grid[n-1][m-1];
    for(int i=n-1;i>=0;i--){
    	dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
    }
     for(int i=m-1;i>=0;i--){
    	dp[n-1][i] = grid[n-1][i] + dp[n-1][i+1];
    }

    for(int i = n-2;i>=0;i--){
    	for(int j=m-2;j>=0;j--){
    		dp[i][j] = grid[i][j] +  min(dp[i+1][j],dp[i][j+1]);
    	}
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<dp[i][j]<<" ";
    	}
    	cout<<"\n";
    }

  /*  queue<pairs> Q;
    Q.push({0,0,"."});

    while(!Q.empty()){
    	pairs node = Q.front();
    	Q.pop();

    	if(node.i == n-1 and node.j == m-1){
    		cout<<node.psf<<"\n";
    	}
    	int x = node.i;
    	int y = node.j;
    	if(dp[x+1][y] == dp[x][y+1]){
    		Q.push({x+1,y,node.psf + "V"});
    		Q.push({x,y+1,node.psf+"H"});
    	}else if(dp[x+1][y] > dp[x][y+1]){
    		Q.push({x,y+1,node.psf+"H"});
    	}else{
    		Q.push({x+1,y,node.psf+"V"});
    	}
    }

*/

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