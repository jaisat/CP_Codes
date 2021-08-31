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

		struct pairs
		{
			int i;
			int j;
			string psf;
		};
		 
		void c_p_c()
		{
		    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		#ifndef ONLINE_JUDGE
		    freopen("input.txt", "r", stdin);
		    freopen("output.txt", "w", stdout);
		#endif
		    int n,tar;
		    cin >> n;
		    vi arr(n);
		    for(int i=0;i<n;i++)
		    	cin >> arr[i];
		    cin >> tar;

		    vector<vector<int> > dp(n+1,vector<int>(tar+1,0));

		    for(int i=1;i<=tar;i++){
		    	dp[0][i] = 0;
		    }

		    for(int i=0;i<=n;i++){
		    	dp[i][0] = 1;
		    }

		    for(int i=1;i<=n;i++){
		    	for(int j=1;j<=tar;j++){

		    		if(j - arr[i-1] >= 0)
		    			dp[i][j] =  dp[i-1][j-arr[i-1]]  || dp[i-1][j];
		    		else
		    			dp[i][j] = dp[i-1][j];
		    	}
		    }
		    if(dp[n][tar]){
		    	cout<<"true"<<"\n";
		    }else{
		    	cout<<"false"<<"\n";
		    }
		    

		    queue<pairs> Q;
		    if(dp[n][tar])
		   	 Q.push({n,tar,""});

			while(!Q.empty()){
				pairs node = Q.front();
				Q.pop();

				int x = node.i;
				int y = node.j;

				if(x == 0 || y == 0){
					cout<<node.psf<<"\n";
		            continue;
				}

			
				if( x - 1 >= 0 and (y - arr[x-1]) >= 0){
					 if(dp[x-1][y-arr[x-1]]){
						Q.push({x-1,y-arr[x-1],to_string(x-1)+" "+node.psf});
					}
				}
					if( x - 1 >= 0 and dp[x-1][y]){
					Q.push({x-1,y,node.psf});
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