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
 
struct rem
{
	int i;
	int l;
	string psf;
};
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vi arr = {10,22,9,33,21,50,41,60,80,1};
    int n = arr.size();
    vi dp(n,1);
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
    	for(int j=i-1;j>=0;j--){
    		if(arr[j] < arr[i]){
    			dp[i] = max(dp[i],dp[j] + 1);
    		}
    	}
    	mx = max(mx,dp[i]);
    }

    cout<<mx<<"\n";
    queue<rem> Q;
    for(int i=0;i<n;i++){
    	if(dp[i] == mx){
    		Q.push({i,dp[i],to_string(arr[i])});
    	}
    }

    while(!Q.empty()){
    	rem node = Q.front();
    	Q.pop();

    	if(node.l == 1){
    		cout<<node.psf<<"\n";
    	}

    	for(int j=node.i - 1; j >= 0;j--){
    		if(arr[j] < arr[node.i] and dp[j] == node.l - 1){
    			Q.push({j,dp[j],to_string(arr[j]) + " -> " + node.psf});
    		}
    	}
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