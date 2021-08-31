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
    int n,m;
    cin >> n >> m;
    vector<vi> arr(n,vi(m));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> arr[i][j];
    	}
    }
    vector<vi> dp1(n+2,vi(m+2,0));
    vector<vi> dp2(n+2,vi(m+2,0));
    vector<vi> dp3(n+2,vi(m+2,0));
    vector<vi> dp4(n+2,vi(m+2,0));

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1]) + arr[i-1][j-1];
    	}
    }

    for(int i=n;i>=1;i--){
    	for(int j=1;j<=m;j++){
    		dp2[i][j] = max(dp2[i][j-1],dp2[i+1][j]) + arr[i-1][j-1];
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=m;j>=1;j--){
    		dp3[i][j] = max(dp3[i-1][j],dp3[i][j+1]) + arr[i-1][j-1];
    	}
    }
    for(int i=n;i>=1;i--){
    	for(int j=m;j>=1;j--){
    		dp4[i][j] = max(dp4[i][j+1],dp4[i+1][j]) + arr[i-1][j-1];
    	}
    }
    int ans = 0;
    for(int i=2;i<n;i++){
    	for(int j=2;j<m;j++){
    		int op1 = dp1[i-1][j] + dp4[i+1][j] + dp2[i][j-1] + dp3[i][j+1];
    		int op2 = dp1[i][j-1] + dp4[i][j+1] + dp2[i+1][j] + dp3[i-1][j];
    		ans = max(ans,max(op1,op2));
    	}
    }
    cout<<ans<<"\n"	;
}
 
int32_t main()
{
    c_p_c();
    return 0;
}