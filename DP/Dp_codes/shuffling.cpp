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
 
int a,b,c;
int dp[33][33][33][2];
int shuffling(int i,int b1,int b2,int carry){
	if(i == 31){
		if(b1 == 0 and b2 == 0 and carry == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if(dp[i][b1][b2][carry] != -1)
	return dp[i][b1][b2][carry];
	int ret = 0;
	if((1<<i)&c){
		if(carry){
			ret = shuffling(i+1,b1,b2,0) + shuffling(i+1,b1-1,b2-1,1);
		}else{
			ret = shuffling(i+1,b1-1,b2,0) + shuffling(i+1,b1,b2-1,0);
		}
	}else{
		if(carry){
			ret = shuffling(i+1,b1-1,b2,1) + shuffling(i+1,b1,b2-1,1);
		}else{
			ret = shuffling(i+1,b1,b2,0) + shuffling(i+1,b1-1,b2-1,1);
		}
	}
	return dp[i][b1][b2][carry] = ret;
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
    	cin >> a >> b >> c;
    	int b1 = setbits(a);
    	int b2 = setbits(b);
    	cout<<shuffling(0,b1,b2,0)<<"\n";
    }
}
int32_t main()
{
    c_p_c();
    return 0;
}
N