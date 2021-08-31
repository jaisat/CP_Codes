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
 
vector<vector<int>> dp;
int n;
bool ValidP(string &s,int i,int sum){
	if(i == n){
		return sum == 0;
	}
	if(dp[i][sum] != -1)
		return dp[i][sum];
	
	int ans;
	if(s[i] == '('){
		
		ans = ValidP(s,i+1,sum+1);
	}else if(s[i] == ')'){
		if(sum == 0)
			return false;
		ans = ValidP(s,i+1,sum-1);
	}else {
		int op3;
		int op1 = ValidP(s,i+1,sum);
		
		int op2 = ValidP(s,i+1,sum+1);
		
		if(sum == 0){
			op3 = false;
		}else{
			
			op3 = ValidP(s,i+1,sum-1);
		}
		ans = (op1 || op2 || op3);
	}
	return dp[i][sum] = ans;

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
  
    n = s.size();
    dp.resize(n,vector<int>(n,-1));

    cout<<ValidP(s,0,0);
   
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