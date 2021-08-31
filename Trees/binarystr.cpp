#include<bits/stdc++.h>
#include<bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


#define max 			1000002
#define ff              first
#define ss              second
//#define int             long long
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
using cmpl = complex<long double>;
constexpr int MAXN = (int)1e6;
int dp[MAXN+2],dp1[MAXN+2];
int next0[MAXN],next1[MAXN];
//int dp[max],dp1[max],next0[max],next01[max];
int max_v(int a,int b){
	if(a >= b)return a;
	return b;
}
void spar(){
		string s;
    	cin >> s;
    	int n = s.length();

    	int last_pos = -1;
    	for(int i=0;i<n;++i){
    		if(s[i] == '0'){
    			for(int j=last_pos+1;j<=i;++j)
    				next0[j] = i;
    			last_pos = i;
    		}
    	}
    	for(int i=last_pos+1;i<n;++i)
    		next0[i] = n;

    	if(next0[0] == n){
    		cout<<"0\n";
    		return;
    	}
    		last_pos = -1;
    		for(int i=0;i<n;++i){
    			if(s[i] == '1'){
    				for(int j=last_pos+1;j<=i;j++){
    					next1[j] = i;
    				}
    				last_pos = i;
    			}
    		}
    		for(int i=last_pos+1;i<n;i++)	
    			next1[i] = n;
    		
    		dp[n] = dp[n+1] = 0;
    		dp1[n] = dp1[n+1] = 0;
    		for(int i=n-1;i>=0;--i){
    			dp[i] = dp[i+1];	
    			if((s[i] == '0') && (next1[i] < n)){
    				dp[i] = max_v(dp[i], dp[next1[i]+1]+1);
    			}
    			if(s[i] == '1' and (next0[i] < n)){
    				dp[i] = max_v(dp[i],dp[next0[i] +1 ] +1);
    			}
    			dp1[i] = dp1[i+1];
    			if(next1[i] < n){
    				dp1[i] = max_v(dp1[i],dp[next1[i]+1] +1);
    			}
    		}
    		int len = dp1[0] +1;
    		int currid = next1[0] + 1;
    		string ans = "1";
    		for(int i=1;i<len;i++){
    			if(currid >= n){
    				ans.push_back('0');
    				continue;
    			}
    			if(next0[currid] >= n){
    				ans.push_back('0');
    				currid = next0[currid] + 1;
    				continue;
    			}
    			if(dp[next0[currid]+1] <len-i-1){
    				ans.push_back('0');
    				currid = next0[currid]+1;
    			}
    			else{
    				ans.push_back('1');
    				currid = next1[currid]+1;
    			}
    		}
    		cout<<ans<<"\n";
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	 spar();
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