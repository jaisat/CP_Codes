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
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int> > dp(n,vector<int>(n,0));

    
    unordered_map<char,int> mp;
    vi next(n+1,-1);
    vi prev(n+1,-1);

    for(int i=0;i<n;i++){

    	if(mp.find(s[i]) != mp.end()){
    		prev[i] = mp[s[i]];
    	}
    	mp[s[i]] = i;
    }
    mp.clear();

    for(int i=n-1;i>=0;i--){
    	if(mp.find(s[i]) != mp.end()){
    		next[i] = mp[s[i]];
    	}
    	mp[s[i]] = i;
    }

    for(int i=0;i<n;i++){
    	int r = 0,c = i;
    	while(c < n){
    		if(r == c){
    			dp[r][c] = 1;
    		}else if ( (c - r) == 1){
    			dp[r][c] = 2;
    		}else{

    			if(s[r] == s[c]){
    				int nextocc = next[r];
    				int prevocc = prev[c];

    				if(nextocc > prevocc){
    					dp[r][c] = ((2 * dp[r+1][c-1]) % mod + 2 % mod ) % mod;
    				}else if(nextocc == prevocc){
    					dp[r][c] = ((2 * dp[r+1][c-1])%mod + 1)%mod;
    				}else{
    					dp[r][c] = ((2 * dp[r+1][c-1]) % mod - dp[nextocc + 1][prevocc - 1]%mod + mod)%mod;
    				}
    			}else{
    				dp[r][c] = (dp[r+1][c] % mod + dp[r][c-1] % mod - dp[r+1][c-1] % mod + mod)%mod;
    			}

    		}
    		r++;
    		c++;
    	}
    }

    cout<<dp[0][n-1]<<"\n";

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