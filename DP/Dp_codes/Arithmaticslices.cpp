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
    vi nums{1,2,3,8,9,10};
   /* if(nums.size() <= 2)
    	return 0;*/
  
   /*O(N^2) solution NOt So Good*/
    int n = nums.size();
  	int count = 0;
    for(int k = 3;k <= n;k++){
    	int i = 0,j = 1;
    	int diff = nums[j] - nums[j-1];
       	j++;
    	for(j;j<n;j++){
    		if(nums[j] - nums[j-1] == diff){
    			
    		}else{
    			i = j - 1;
    			diff = nums[j] - nums[j-1];
    		}
    		if(j - i + 1 == k){
    			//cout<<j<<" "<<i<<"\n";
    			count++;
    			i++;
    		}
    	}
    }
    cout<<count<<"\n";

    /*O(N) DP Solution*/

    vector<int> dp(n,0);
    if(A[2] - A[1] == A[1] - A[0])
    	dp[2] = 1;
    int ans = 0;
    for(int i=3;i<n;i++){
    	if(A[i] - A[i-1] == A[i-1] - A[i-2])
    		dp[i] = dp[i-1] + 1;
    	ans += dp[i];
    }
    cout<<ans<<"\n";
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