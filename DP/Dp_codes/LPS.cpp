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
int LPS(string &s,int i,int j){
	if(i == j)
		return 1;
	if(i > j)
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;
	if(s[i] == s[j]){
		ans = max(ans,2 + LPS(s,i+1,j-1));
	}else{
		int op1 = LPS(s,i+1,j);
		int op2 = LPS(s,i,j-1);
		ans = max({ans,op1,op2});
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
    string s;
    cin >> s;
   /* memset(dp,-1,sizeof dp);
    cout<<LPS(s,0,s.size()-1)<<"\n";*/
    int n = s.size();

    for(int i=0;i<n;i++){
    	int r = 0,c = i;
    	while(c < n){

    		if(r == c){
    			dp[r][c] = 1;
    		}
  			else if(s[r] == s[c]){
  				dp[r][c] = 2 + dp[r+1][c-1];
  			}else{
  				dp[r][c] = max(dp[r][c-1],dp[r+1][c]);
  			}

    		r++;
    		c++;
    	}
    }

    cout<<dp[0][n-1]<<"\n";

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