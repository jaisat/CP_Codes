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
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int> > dp(n,vector<int>(n));

    for(int i=0;i<n;i++){
        int r = 0,c = i;
        while(c < n){
            if(r == c){
                dp[r][c] = 1;
            }else if(s[r] == s[c]){
                dp[r][c] = dp[r+1][c-1];
            }else{
                dp[r][c] = 0;
            }
            r++;
            c++;
        }
    }

// O(N^3) solution....
/*    vector<vector<int> > dp2(n,vector<int>(n));
*/
  /*  for(int i=0;i<n;i++){
        int r = 0,c = i;
        while(c < n){
            if(r == c){
                dp2[r][c] = 0;
                r++;
                c++;
                continue;
            }
            if(dp[r][c]){
                dp2[r][c] = 0;
            }else{
                int ans = INT_MAX;
                for(int k =r;k<c;k++){
                    ans = min(ans,dp2[r][k]+dp2[k+1][c]+1);
                }
                 dp2[r][c] = ans;
            } 
            r++;
            c++;
        }
    }*/

    // O(N^2)   solution. 
    vector<int> dp2(n);

    for(int j=1;j<n;j++){
        int ans = INT_MAX;
        for(int i=j;i>=1;i--){

            if(dp[i][j]){
                ans = min(ans,dp2[i-1]);
            }
        }
        dp2[j] = ans + 1;
    }
    cout<<dp2[n-1];

   /* cout<<dp2[0][n-1];
*/

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