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
 
int dp[1000][1000];
vi arr;
int n;
int NoofLIS(int id,int prev){
	if(id == n)
		return 1;

	if(dp[id][prev] != -1)
		return dp[id][prev];

	int ans = 0;
	ans += NoofLIS(id+1,prev);
	if(arr[id] > prev){
		ans += 1 + NoofLIS(id+1,arr[id]);
	}
	return dp[id][prev] = ans;
}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    arr = {2,2,2,2,2};
    n = arr.size();
   /* memset(dp,-1,sizeof dp);
    cout<<NoofLIS(0,0);*/
    int mx = 0;
    int idx = -1;
    vi cnt(n,0);
    int res = 0;
    vector<pii> dp(n,{1,1});
    for(int i=0;i<n;i++){
    	
    	for(int j=i-1;j>=0;j--){
    		if(arr[j] < arr[i]){
    			if(dp[i].ff < 1 + dp[j].ff){
    				dp[i].ff = 1 + dp[j].ff;
    				dp[i].ss = dp[j].ss;
    				

    			}else if (dp[i].ff == 1 + dp[j].ff){
    				dp[i].ss += dp[j].ss;
    			}
    			
    		}
    	}
    	if(mx == dp[i].ff) res += dp[i].ss;
    	if(mx < dp[i].ff){
    		mx = dp[i].ff;
    		res = dp[i].ss;
    	}
    	
    }

   cout<<res<<"\n";
    



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