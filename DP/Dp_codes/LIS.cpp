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

//vector<vector<int> > dp;
vector<int> arr;
int n;
/*int LIS(int i,int prev){
	if(i == n)
		return 0;
	if(dp[i][prev] != -1)	
		return dp[i][prev];

	int ans = 0;
	ans = max(ans,LIS(i+1,prev));
	if(prev < arr[i]){
		ans = max(ans,1 + LIS(i+1,arr[i]));
	}
	return dp[i][prev] = ans;
}*/
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

   // dp.resize(n,vi(105,-1));
w
    //cout<<LIS(0,0)<<"\n";
  /*  set<int> s;
    for(auto x : arr){
    	auto it = s.lower_bound(x);
    	if(it != s.end()){
    		s.erase(it);
    	}
    	s.insert(x);
    }

    cout<<s.size()<<"\n";*/
    vi dp(n,1);

    dp[0] = 1;
    int mx = 0;
    for(int i=1;i<n;i++){
    	for(int j = i -1;j>=0;j--){
    		if(arr[j] < arr[i])
    		dp[i] = max(dp[i],1 + dp[j]);
    		
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