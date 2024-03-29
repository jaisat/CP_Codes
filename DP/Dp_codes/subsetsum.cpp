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
 
int dp[100][100];
vi arr;
int L;
bool SubsetSum(int n,int sum){
	if(n == 0 and sum == 0)
		return false;
	if(sum == 0 and n != L)
		return true;
	if(n == 0)
		return false;

	if(dp[n][sum] != -1)
		return dp[n][sum];
	if(sum + arr[n-1] < 0){
		return dp[n][sum] = SubsetSum(n-1,sum);
	}
	return dp[n][sum] = SubsetSum(n-1,sum+arr[n-1]) || SubsetSum(n-1,sum);
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	memset(dp,-1,sizeof(dp));
    	int n;
    	cin>>n;
    	L = n;
    	arr.resize(n);
    	for(int i=0;i<n;i++) cin>>arr[i];
    	if(SubsetSum(n,0)){
    		cout<<"Yes"<<"\n";
    	}else{
    		cout<<"No"<<"\n";
    	}
    }
}
int32_t main()
{
    c_p_c();
    return 0;
}