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
 
    double dp[26][26][101];
    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {1,-1,2,-2,2,-2,1,-1};
    
    double dfs(int i,int j,int n,int k){
            
        if(i < 0 || i >= n || j < 0 || j >= n){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        
        if(dp[i][j][k] != 0)
            return dp[i][j][k];
        
        double rate = 0;
        for(int d = 0; d < 8; d++){
            int x = i + dx[d];
            int y = j + dy[d];
            
            rate += (0.125 * dfs(x,y,n,k-1));                         
        }
   
        return dp[i][j][k] = rate;
    }
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    	int r = 0,c = 0,n=3,k=2;
       memset(dp,0,sizeof dp);
       cout<<dfs(r,c,n,k);
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