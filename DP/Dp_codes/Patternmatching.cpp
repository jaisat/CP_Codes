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
 

 
void c_p_c()
{	
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s1,s2;
    cin >> s1 >> s2;

     int n = s1.size();
     int m = s2.size();
     vector<vector<int> > dp(m+1,vector<int>(n+1));

       for(int i=0;i<=m;i++){
     	for(int j=0;j<=n;j++){
     		if(i == 0 and j == 0){
     			dp[i][j] = true;
     		}else if(i == 0){
     			dp[i][j] = false;
     		}else if (j == 0){
     			if(s2[i-1] == '*'){	
     				dp[i][j] = dp[i-2][j];
     			}else{
     				dp[i][j] = false;
     			}
     		}else{
     			char pc = s2[i-1];
     			char sc = s1[j-1];

     			if(pc == '*'){	
     				dp[i][j] = dp[i-2][j];
     				char prev = s2[i-2];
     				if(prev == '.' || prev == s1[j-1]){
     					dp[i][j] = dp[i][j] || dp[i][j-1];
     				}
     			}else if(pc == '.'){
     				dp[i][j] = dp[i-1][j-1];
     			}else if(pc == sc){
     				dp[i][j] = dp[i-1][j-1];
     			}else{
     				dp[i][j] = false;
     			}
     		}
     	}
     }
     if(dp[m][n]){
     	cout<<"true"<<"\n";
     }else{
     	cout<<"false"<<"\n";
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