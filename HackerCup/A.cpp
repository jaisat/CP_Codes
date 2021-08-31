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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
    	string s;
    	cin >> s;
    	unordered_map<char,int> mp;
    	for(auto ch : s){
    		mp[ch]++;
    	}

    	int mx_v = 0;
    	int mx_c = 0;
    	int n = s.size();
    	int f_v = 0;
    	int f_c = 0;
    	for(auto x : mp){
    		if(x.ff == 'A' || x.ff == 'E' || x.ff == 'I' || x.ff == 'O' || x.ff == 'U'){
    			mx_v = max(mx_v,mp[x.ff]);
    			f_v += mp[x.ff];
    		}else{
    			mx_c = max(mx_c,mp[x.ff]);
    			f_c += mp[x.ff];
    		}
    	}

    	int ans = min((f_v - mx_v) * 2 + f_c , (f_c - mx_c) * 2 + f_v);
    	cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
	/*#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif */
    return 0;
}