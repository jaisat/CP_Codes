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
 
int n,k;
vi arr;
int dp[55][55][55];
int j;
int func(int i,int open,int close){
	if(i == 2 * n){
		return 1;
	}
	if(dp[i][open][close] != -1)
		return dp[i][open][close];
	if( j < k and (i == arr[j]-1)){ 
		if(open < n){
			j++;
			return dp[i][open][close] = func(i+1,open+1,close);
		}else return dp[i][open][close] = 0;
	}
	int op1 = 0;
	int op2 = 0;
	if(open < n){
		op1 = func(i+1,open+1,close);
	}
	if(close < open){
		op2 = func(i+1,open,close+1);
	}

	return dp[i][open][close] = (op1 % mod + op2 % mod) % mod;

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	j = 0;
    	memset(dp,-1,sizeof(dp));
    	cin >> n >> k;
    	arr.resize(k,0);
    	for(int i=0;i<k;i++) cin >> arr[i];
    	/*cout<<n<<k<<endl;
    	for(int i=0;i<k;i++) cout<< arr[i]<<"\n";*/
    	sort(arr.begin(),arr.end());
    	cout<<func(0,0,0)<<"\n";
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}