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
 
vector<vi> v;
int dp[100005][3];
int price(int n,int id){
	if(n == 0){
		return 0;
	}
	if(dp[n][id] != -1){
		return dp[n][id];
	}
	int ret;
	if(id == 0){
		ret = min(v[n][1]+price(n-1,1),v[n][2]+price(n-1,2));
	}else if(id == 1){
		ret = min(v[n][0]+price(n-1,0),v[n][2]+price(n-1,2));

	}else{
		ret = min(v[n][1]+price(n-1,1),v[n][0]+price(n-1,0));
	}
	return dp[n][id] = ret;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	memset(dp,-1,sizeof(dp));
    	int n;
    	cin >> n;
    	v.resize(n+1,vi(3));
    	for(int i=1;i<=n;i++){
    		for(int j=0;j<=2;j++){
    			cin >> v[i][j];
    		}
    	}
    	int ans = min({v[n][0]+price(n-1,0),v[n][1]+price(n-1,1),v[n][2]+price(n-1,2)});
    	cout<<ans<<"\n";
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}