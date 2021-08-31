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

int n,m,N;
int dp[105][105];
int func(int i,int j){
	if(i >=n and j >= m and i+j >= N)
		return true;

	if(i+j >= N)
		return false;

	if(dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = (s1[i] == s3[i+j] and func(i+1,j)) || (s2[j] == s3[i+j] and func(i,j+1));
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    n = s1.size();
    m = s2.size();
    N = s3.size();

    if(n+m != N)
    	return false;

    /*return func(0,0); TOP DOWN*/

    /*BOTTOM UP APPROACH*/

    vector<vector<int> > dp(n+1,vector<int>(m,0));

    dp[0][0] = true;

    for(int i=1;i<=n;i++)
    	dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1];
    for(int j=1;j<=m;j++)
    	dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1];

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){

    		bool s1_s3 = s1[i-1] == s3[i+j-1] and dp[i-1][j];
    		bool s2_s3 = s2[j-1] == s3[i+j-1] and d[i][j-1];

    		dp[i][j] = s1_s2 || s1_s3;
    	}
    }
    return dp[n][m];
    
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