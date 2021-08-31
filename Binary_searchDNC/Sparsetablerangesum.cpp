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
 
const int MAXN = 1e5;
int dp[MAXN][25];

void build(vector<int> &v){
	int N = v.size();
	for(int i=0;i < N;i++){
		dp[i][0] = v[i];
	}

	for(int j=1;j<25;j++){
		for(int i =0;i + (1 << j) <= N; i++){
			dp[i][j] = dp[i][j-1] + dp[i + (1 << (j - 1))][j-1];
		}
	}
    
    for(int i=0;i<N;i++){
        for(int j=0;j<20;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int Query(int L,int R){
	int w = R - L + 1;
	int ans = 0;
	int l = L;
	for(int i = 20;i>=0;i--){
		if( (w & (1 << i)) == 0) continue;
		int r = i;
        //cout<<l<<" "<<r<<"\n";
		ans += dp[l][r];
		l = l + ( 1 << i);
	}
	return ans;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vi v{1,2,4,6,7,3};
    build(v);
    cout<<Query(3,5)<<"\n";
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