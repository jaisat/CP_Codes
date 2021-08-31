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
 
string s1,s2;
vector<vector<int> > dp;

int WildCard(int i,int j){
	if(i == s1.size() and j == s2.size())
		return 1;
	if(i == s1.size() || j == s2.size())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ans;
	if(s1[i] == s2[j]){
		ans = WildCard(i+1,j+1);
	}else{
		if(s2[j] == '?'){
			ans = WildCard(i+1,j+1);
		}else if(s2[j] == '*'){
			ans = WildCard(i+1,j) || WildCard(i,j+1) || WildCard(i+1,j+1);
		}else{
			ans = 0;
		}
	}
	return dp[i][j] = ans;
}

 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s1 >> s2;
    dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
    cout<<WildCard(0,0)<<"\n";
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