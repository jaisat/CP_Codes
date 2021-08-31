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
 
int dp[1002][1002];
int DistictSubseq(string s,string t,int i,int j){
	if(i == s.size() and j == t.size()){
		return 1;
	}
	if(i ==s.size()){
		return 0;
	}
	if(j == t.size()){
		return 1;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int ans = 0;
	if(s[i] == t[j]){
		ans = DistictSubseq(s,t,i+1,j+1) + DistictSubseq(s,t,i+1,j); 
	}else{
		ans = DistictSubseq(s,t,i+1,j);
	}
	return dp[i][j] = ans;

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s,t;
    cin >> s >> t;
/*    memset(dp,-1,sizeof dp);
    cout<< DistictSubseq(s,t,0,0)<<"\n";*/

    int n = s.size();
    int m = t.size();
    vector<vector<int> > dp(n+1,vector<int>(m+1));

    for(int i=0;i<=n;i++){
    	dp[i][0] = 1;
    }

    for(int j=0;j<=m;j++)
    	dp[0][j] = 0;

    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(s[i-1] == t[j-1]){
    			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    		}else{
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }
    cout<<dp[n][m];

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