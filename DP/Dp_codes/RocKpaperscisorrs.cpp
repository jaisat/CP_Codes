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
 
double dp[105][105][105];
void set_dp(){
	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			for(int k=0;k<105;k++)
				dp[i][j][k] = -1.0;
}
double f1(int r,int p,int s){
	if(r == 0 || s == 0)
	return 0.0;
	if(p == 0)
	return 1.0;
	if(dp[r][p][s] != -1)
	return dp[r][p][s];
	double tot = r*s + s*p + p*r;
	double ans = 0.0;

	ans += f1(r-1,p,s) * ((r*p)/tot);
	ans += f1(r,p-1,s) * ((p*s)/tot);
	ans += f1(r,p,s-1) * ((r*s)/tot);

	return dp[r][p][s] = ans;

} 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	int r,s,p;
    	cin >> r >> s >> p;
     	set_dp();
     	double ans1 = f1(r,p,s);
  		set_dp();	
  		double ans2 = f1(p,s,r);
  		set_dp();
     	double ans3 = f1(s,r,p);
    	cout<<ps(ans1,9)<<" ";	   
    	cout<<ps(ans2,9)<<" ";
    	cout<<ps(ans3,9)<<" "<<"\n";
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}