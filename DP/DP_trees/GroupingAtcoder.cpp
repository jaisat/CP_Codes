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
#define vv 				vector<vector<int> > 
#define inf 1e18
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



vi dp((1<<16),inf);
vi score((1<<16),0);
int calc(vv &A,int subset){
	int ans = 0;
	for(int i=0;i<=16;i++){
		for(int j=i+1;j<=16;j++){
			if(((subset&(1<<i)) != 0) and ((subset&(1<<j)) != 0))
				ans += A[i][j];
		}
	}
	return ans;
}

void precompute(vv &A,int n){
	for(int subset=1;subset<= ((1<<n)-1) ;subset++){
		score[subset] = calc(A,subset);
	}
}
int func(vv &A,int mask){
	if(mask == 0)
		return 0;
	if(dp[mask] != inf)
		return dp[mask];
	int ans = 0;
	for(int submask = mask; submask != 0; submask =  mask & (submask-1)){
		ans = max(ans,score[submask]+func(A,mask^submask));
	}
	return dp[mask] = ans;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int> > A(n,vector<int>(n));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin >> A[i][j];
    	}
    }
    precompute(A,n);
    cout<<func(A,(1<<n)-1);
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
	// #ifndef ONLINE_JUDGE 
	//   clock_t end = clock();
	//   cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	// #endif 
    return 0;
}