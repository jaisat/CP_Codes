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

struct box
{
	int l,w,h;
	box(){}
	box(int l,int w,int h){
		this->l = l;
		this->w = w;
		this->h = h;
	}
};
int dp[105][3];
int BoxStack(vector<box> &v,int prevbox,int orient){
	if(dp[prevbox][orient] != -1)
		return dp[prevbox][orient];
	int res = 0;
	int prev_l,prev_w,prev_h;
	if(orient == 0){
		prev_l = v[prevbox].l;
		prev_w = v[prevbox].w;
		prev_h = v[prevbox].h;
	}else if(orient == 1){
		prev_l = v[prevbox].w;
		prev_w = v[prevbox].h;
		prev_h = v[prevbox].l;

	}else{
		prev_l = v[prevbox].h;
		prev_w = v[prevbox].l;
		prev_h = v[prevbox].w;
	}
	for(int i=1;i<v.size();i++){
		if((v[i].l < prev_l and v[i].w < prev_w) || (v[i].w < prev_l and v[i].l < prev_w))
			res = max(res,v[i].h+BoxStack(v,i,0));
		if((v[i].w < prev_l and v[i].h < prev_w) || (v[i].h < prev_l and v[i].w < prev_w))
			res = max(res,v[i].l+BoxStack(v,i,1));
		if((v[i].l < prev_l and v[i].h < prev_w) || (v[i].h < prev_l and v[i].l < prev_w))
			res = max(res,v[i].w+BoxStack(v,i,2));
	}
	return dp[prevbox][orient] = res;	
} 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    w(x){
    	memset(dp,-1,sizeof(dp));
    	cin>>n;
    	vector<box> v(n+1);
    	v[0] = box(1000001,1000001,1000001);
    	for(int i=1;i<=n;i++){
    		cin >> v[i].l >> v[i].w >> v[i].h;
    	}
    	cout<<BoxStack(v,0,0)<<"\n";
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}