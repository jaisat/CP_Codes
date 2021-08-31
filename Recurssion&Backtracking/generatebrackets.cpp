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
 
void generate_brackets(char *out,int idx,int n,int open,int close){
	if(idx == 2 * n){
		out[idx] = '\0';
		cout<<out<<endl;
		return;
	}

	if(open < n){
		out[idx] = '(';
		generate_brackets(out,idx+1,n,open+1,close);
	}

	if(close < open){
		out[idx] = ')';
		generate_brackets(out,idx+1,n,open,close+1);
	}
	return;
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
    char out[1000];
    int idx = 0;
    generate_brackets(out,idx,n,0,0);
}
 
int32_t main()
{
    c_p_c();
    return 0;
}