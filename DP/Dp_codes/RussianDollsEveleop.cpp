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
 
vi dp;
int n;
int maxnoofEnv(vector<vi> envelops, int idx){

	if(dp[idx] != -1)
		return dp[idx];

	int ans = 0;
	int w =  (idx == n) ? INT_MAX : envelops[idx][0];
	int h =  (idx == n) ? INT_MAX : envelops[idx][1];
	for(int i=0;i < envelops.size();i++){
		int W = envelops[i][0];
		int H = envelops[i][1];

		if(w > W and h > H)
		ans = max(ans, 1 + maxnoofEnv(envelops,i));
	}	

	return dp[idx] = ans;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  
      cin >> n;
      vector<vi> envelops(n,vi(2));
   // n = envelops.size();
    for(int i=0;i<n;i++){
    	int x,y;
    	cin >> x >> y;
    	
    	envelops[i] = {x,y};
    }
 /*   dp.resize(n+1,-1);
    cout<< maxnoofEnv(envelops, n)<<"\n"; */

    sort(envelops.begin(),envelops.end());

    vi dp(n,1);
    int  mx = INT_MIN;
    for(int i=0;i<n;i++){
    	for(int j=i-1;j>=0;j--){
    		if(envelops[i][1] > envelops[j][1] and envelops[i][0] > envelops[j][0]){
    			dp[i] = max(dp[i],1 + dp[j]);
    		}
    	}
    	mx = max(mx,dp[i]);
    }
    cout<<mx<<"\n";
  
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