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
 
vector<vi> dp;
int n;
vi arr;
int LIMS(int id,int prev){
	if(id == n)
		return 0;

	if(dp[id][prev] != -1)
		return dp[id][prev];

	int ans = 0;
	ans = max(ans,LIMS(id+1,prev));
	if(prev <= arr[id]){
		ans = max(ans,arr[id] + LIMS(id+1,arr[id]));
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
    
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    	cin >> arr[i];

 /*   dp.resize(n,vi(105,-1));

    cout<<LIMS(0,0)<<"\n";*/

    vi dp(n,0);
    vi parent(n,-1);
    int mx = INT_MIN;
    int idx = -1;
    int maxidx = 0;

    for(int i=0;i<n;i++){
    	dp[i] = arr[i];
    	for(int j=i-1;j>=0;j--){
    		if(arr[j] <= arr[i]){
    			if(dp[i] < dp[j] + arr[i]){
    				parent[i] = j;
    				dp[i] = dp[j] + arr[i];
    			}
    		}
    	}
    	if(dp[i] > mx){
    		maxidx = i;
    		mx = dp[i];
    	}
    }
    idx = maxidx;
    vi ans;
    while(idx != -1){
    	ans.pb(arr[idx]);
    	idx = parent[idx];
    }
    reverse(ans.begin(),ans.end());
    for(auto x : ans){
    	cout<<x<<" ";
    }
    cout<<"\n";

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