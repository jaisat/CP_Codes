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
	 
	 
	set<int> s;
	vector<int> g[10000];
	void findPrime(){
		int isprime;
		for(int i=1000;i<=9999;i++){
			isprime = 1;
			for(int j=2;j*j<=i;j++){
				if(i % j == 0){
					isprime = 0;
				}
			}
			if(isprime){
				s.insert(i);
			}
		}
			//cout<<s.size()<<"\n";
	/*	for(auto x : s){
			cout<<x<<" ";
		}*/
	}
	bool onechange(int a,int b){
		string a1 = to_string(a);
		string a2 = to_string(b);
		int change = 0;
		for(int i=0;i<a1.size();i++){
			if(a1[i] != a2[i])
				change++;
		}
		return (change == 1);
	}
	void c_p_c()
	{
	    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    findPrime();
	    for(auto x : s){
	    	for(auto y : s){
	    		if(onechange(x,y)){
	    			g[x].pb(y);
	    			g[y].pb(x);
	    		}
	    	}
	    }
	    w(x){
	    	int n,m;
	    	cin >> n >> m;
	    	n = min(n,m);
	    	m = max(n,m);
	    	vector<int> vis(10000,0);
	    	int impossible = 1;
	    	queue<int> Q;
	    	Q.push(n);
	    	Q.push(-1);
	    	vis[n] = true;
	    	int cnt = 0;
	    	while(!Q.empty()){
	    		int node = Q.front();
	    		Q.pop();

	    		if(node == -1 and !Q.empty()){
	    			Q.push(-1);
	    			cnt++;
	    			continue;
	    		}
	    		if(node == m){
	    			impossible = 0;
	    			break;
	    		}

	    	/*	for(auto x : s){
	    			if(!vis[x] and onechange(x,node)){
	    				Q.push(x);
	    				vis[x] = true;
	    			}
	    		}*/
	    		if(node == -1)
	    			continue;
	    		for(auto nbr : g[node]){
	    			if(!vis[nbr]){
	    				Q.push(nbr);
	    				vis[nbr] = true;
	    			}
	    		}
	    	}
	    	if(impossible){
	    		cout<<"Impossible"<<"\n";
	    	}else{
	    		cout<<cnt<<"\n";
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