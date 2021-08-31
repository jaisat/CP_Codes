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
	 
	struct minJumps
	{	
		int i;
		int jumps;
		string psf;
	};
	void c_p_c()
	{
	    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    int n;
	    cin >> n;
	    vi arr(n);
	    for(int i=0;i<n;i++){
	    	cin >> arr[i];
	    }

	    vi dp(n,INT_MAX);
	 	dp[n-1] = 0;
	    for(int i=n-2;i>=0;i--){
	    	//int jumps = arr[i];
	    	for(int j = i+1; j <= i + arr[i] and j < n; j++){
	    		if(dp[j] == INT_MAX)
	    			continue;

	    		dp[i] = min(dp[i],1 + dp[j]);
	    	}
	    }
	  	
	  	cout<<dp[0]<<"\n";
	  	queue<minJumps> Q;
	  	Q.push({0,dp[0], "0"});
	  	while(!Q.empty()){
	  		minJumps node = Q.front();
	  		Q.pop();

	  		if(node.jumps == 0){
	  			cout<<node.psf + " ."<<"\n";
	  		}


	  		for(int j = node.i + 1; j <= node.i + arr[node.i] and j < n;j++){
	  			if(dp[j] == dp[node.i] - 1){
	  				Q.push({j,dp[j],node.psf+" -> " +to_string(j)});
	  			}
	  		}

	  	}


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