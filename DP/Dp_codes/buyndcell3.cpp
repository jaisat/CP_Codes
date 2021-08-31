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

const int N = 1e5 + 5;
int dp[N][2][10];
int n;

int func(vector<int> &A,int i,int id,int trans){
	if(i == A.size()){
		return 0;
	}
	if(trans == 2){
		return 0;
	}
	if(dp[i][id][trans] != -1){
		return dp[i][id][trans];
	}
	int op1,op2;
	if(id == 1){
		op1 = func(A,i+1,1,trans);
		op2 = func(A,i+1,0,trans) - A[i];
	}
	if(id == 0){
		op1 = func(A,i+1,0,trans);
		op2 = func(A,i+1,1,trans+1) + A[i];
	}
	return dp[i][id][trans] = max(op1,op2);
}
int buyndsell(vi &A){
	int fb = INT_MIN,fs = 0,sb = INT_MIN,ss = 0;
	for(int i=0;i<A.size();i++){
		fb = max(fb,-A[i]);
		fs = max(fs,fb+A[i]);
		sb = max(sb,fs-A[i]);
		ss = max(ss,sb+A[i]);
	}
	return ss;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    memset(dp,-1,sizeof dp);
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    cout<<func(A,0,1,0)<<"\n";
	cout<<buyndsell(A)<<"\n";\
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