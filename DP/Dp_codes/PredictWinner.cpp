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
    vi nums = {1,5,233,7};
    int n = nums.size();
    int sum =0;
    for(int i=0;i<n;i++){
    	sum += nums[i];
    }
    vector<vector<int> > dp(n,vector<int>(n));

    for(int i=0;i<n;i++){
    	int r = 0,c = i;
    	while(c < n){	

    		int x = (r+2 <= c) ? dp[r+2][c] : 0;
    		int y = (r+1 <= c-1) ? dp[r+1][c-1] : 0;
    		int z = (r <= c-2) ? dp[r][c-2] : 0;

    		int op1 = nums[r] + min(x,y);
    		int op2 = nums[c] + min(y,z);
    		dp[r][c] = max(op1,op2);

    		r++;	
    		c++;
    	}
    }
    if(dp[0][n-1] >= (sum - dp[0][n-1])){
    	cout<<"YEs";
    }else{
    	cout<<"No";
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