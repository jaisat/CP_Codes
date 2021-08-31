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

int n,m;
int dp[2002][2002];
bool Wildcard(int i,int j,string &s1,string &s2){
	if(i == n and j == m)
		return 1;
	if(i == n and j == (m-1) and s2[j] == '*')
		return 1;
	if(i == n || j == m)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	if(s1[i] == s2[j]){
		return Wildcard(i+1,j+1,s1,s2);
	}

	if(s2[j] == '*'){
		return dp[i][j] = Wildcard(i,j+1,s1,s2) || Wildcard(i+1,j,s1,s2);
	}
	if(s2[j] == '?'){
		return dp[i][j] = Wildcard(i+1,j+1,s1,s2);
	}	

	return dp[i][j] = 0;
} 

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1,s2;
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    memset(dp,-1,sizeof dp);
     for(int i=0; i + 1 < s2.size();i++){
        if(s2[i] == '*' && s2[i+1] == '*'){
            s2.erase(i,1);
            i--;
        }
    }

    cout<<Wildcard(0,0,s1,s2)<<"\n";
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