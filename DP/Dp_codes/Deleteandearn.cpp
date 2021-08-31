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
 
int dp[20005];
vi arr;
int n;
int DeleteandEarn(int idx){
	if(idx == n)
		return 0;

	if(dp[idx] != -1)
		return dp[idx];

	int next = idx;
	int sum = 0;
	int ans = 0;

	while(next < n and arr[idx] == arr[next]){
		sum += arr[next];
		next++;
	}

	while(next < n  and arr[next] == arr[idx]+1 ){
		next++;
	}

	ans = max(ans,DeleteandEarn(idx+1));
	ans = max(ans,sum + DeleteandEarn(next));
	

	return dp[idx] = ans;

}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    arr = {3,2,4};
    n = arr.size();
    memset(dp,-1,sizeof dp);
    sort(arr.begin(),arr.end());
    cout<<DeleteandEarn(0);
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