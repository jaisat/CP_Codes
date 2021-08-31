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

	int const N = 1e5 + 5;
	int ans = 0;
	int n;
	int ma[N],mi[N];
	int W[N],P[N];
	vector<vector<int> > adj { N };int solve(int mask,iint solve(int mask,int m){
	if(mask == (1<<s.size()) - 1){
		return (m == 0);
	}
	if(dp[mask][m] != -1){
		return dp[mask][m];
	}

	int ans = 0;
	bool ch[10];
	memset(ch,0,sizeof(ch));
	for(int i=0;i<s.size();i++){
		if(s[i] == '0'){
			if(mask == 0)
				continue;
		}
		if((mask&(1<<i)) == 0 and ch[s[i]-'0'] == 0 ){
			ans  = ans + solve(mask|(1<<i),(m*10+ (s[i] - '0')) % MOD);
			ch[s[i] - '0'] = 1;
		}
	}
	return dp[mask][m] = ans; 	nt m){
	if(mask == (1<<s.size()) - 1){
		return (m == 0);
	}
	if(dp[mask][m] != -1){
		return dp[mask][m];
	}

	int ans = 0;
	bool ch[10];
	memset(ch,0,sizeof(ch));
	for(int i=0;i<s.size();i++){
		if(s[i] == '0'){
			if(mask == 0)
				continue;
		}
		if((mask&(1<<i)) == 0 and ch[s[i]-'0'] == 0 ){
			ans  = ans + solve(mask|(1<<i),(m*10+ (s[i] - '0')) % MOD);
			ch[s[i] - '0'] = 1;
		}
	}
	return dp[mask][m] = ans; 	
	void dfs(int i,int par){
		for(auto it : adj[i]){
			if(it != par){
				dfs(it,i);
				ma[i] = max(ma[i],ma[it]);
				mi[i] = min(mi[i],mi[it]);
			}
		}
		ma[i] = max(ma[i],W[i]);
		mi[i] = min(mi[i],W[i]);
		ans = max(ans,abs(W[i]-ma[i]));
		ans = max(ans,abs(W[i]-mi[i]));
	}
	void c_p_c()
	{
	    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    cin >> n;
	    for(int i=1;i<=n;i++){
	    	ma[i] = INT_MIN;
	    	mi[i] = INT_MAX;
	    }
	    int root = 0;
	    for(int i=1;i<=n;i++){
	    	cin >> W[i];
	    }
	    for(int i=1;i<=n;i++){
	    	cin >> P[i];
	    	if(P[i] == -1){
	    		root = i;
	    	}else{
	    		adj[P[i]].pb(i);
	    	}
	    }
	    dfs(root,-1);
	    cout<<ans<<"\n";
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