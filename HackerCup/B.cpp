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
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
   	int t;
   	cin >> t;
   	for(int t1=1;t1<=t;t1++){

   		int n;
   		cin >> n;
   		vector<vector<char>> grid(n,vector<char>(n));
   		for(int i=0;i<n;i++){
   			for(int j=0;j<n;j++){
   				cin >> grid[i][j];
   			}
   		}

   		set<pair<int,int> > st;
   		int c;
   		map<int,int> mp;
   		for(int i=0;i<n;i++){

   			int flag = 1;
   			int em = 0;
   			for(int j=0;j<n;j++){
   				if(grid[i][j] == 'O'){
   					flag = 0;
   					break;
   				}

   				if(grid[i][j] == '.'){
   					c = j;
   					em++;
   				}
   			}



   			if(flag){
	   			if(em == 1){
	   				if(st.find({i,c}) == st.end()){
	   					st.insert({i,c});
	   					mp[em]++;
	   				}
		   		}else{
		   			mp[em]++;
		   		}
	   		}
   		}

   		int c2;
   		for(int j=0;j<n;j++){

   			int flag = 1;
   			int em = 0;
   			for(int i=0;i<n;i++){
   				if(grid[i][j] == 'O'){
   					flag = 0;
   					break;
   				}

   				if(grid[i][j] == '.'){
   					c2 = i;
   					em++;
   				}
   			}

   			if(flag){
	   			if(em == 1){
	   				if(st.find({c2,j}) == st.end()){
	   					st.insert({c2,j});
	   					mp[em]++;
	   				}
		   		}else{
		   			mp[em]++;
		   		}
	   		}
   		}

   		auto ans = *(mp.begin());
   		if(mp.empty())
			cout<<"Case #"<<t1<<": "<<"Impossible"<<"\n";	
		else
			cout<<"Case #"<<t1<<": "<<ans.ff<<" "<<ans.ss<<"\n";	
   	}
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
/*	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif*/ 
    return 0;
}