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
 
/*bool CanPartitionKsubsetsfrom(vector<int> &nums,int k ,vector<int>&visited,int target,int curr,int idx){
	if(k == 0)
		return true;

	if(curr == target){
		return CanPartitionKsubsetsfrom(nums,k-1,visited,target,0,0);
	}

	for(int i = idx;i<nums.size();i++){
		if(!visited[i] and curr + nums[i] <= target){
			visited[i] = true;
			if(CanPartitionKsubsetsfrom(nums,k,visited,target,curr+nums[i],i+1)){
				return true;
			}
			visited[i] = false;
		}
	}
	return false;
}

bool CanPartitionKsubsets(vector<int>& nums,int k){
	int sum = 0;
	int maxNum = 0;
	for(auto &x : nums){
		sum += x;
		maxNum = max(maxNum,x);
		
	}
	if(sum % k != 0 || maxNum > sum / k)
		return false;

	vector<int> visited(nums.size(),false);
	return CanPartitionKsubsetsfrom(nums,k,visited,sum/k,0,0);	
}*/

/*=============
DP WITH BITMASK SOL.
=============*/
vi nums{4,3,2,3,5,2,1};
int dp[(1<<17)];
int n;

bool func(int mask,int curr,int target,int k,int idx){
	
	//int idx = setbits(mask);
	if(curr == target){
		return dp[mask] = func(mask,0,target,k-1,0);
	}

	/*if(idx == n){
		return k == 0;
	}*/
	if(k == 0)
		return true;
	if(idx == n)
		return false;
	/*if(k == 0)
		return true;*/
	if(dp[mask] != -1)
		return dp[mask];

	

	for(int i=idx;i<n;i++){
		if(((mask & (1<<i)) == 0) and curr + nums[i] <= target ){
			if(func((mask | (1<<i)),curr+nums[i],target,k,i+1)){
				return dp[mask] = true;
			}
		}
	}
	return dp[mask] = false;
}


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  /*  memset(dp,-1,sizeof dp);
    vi nums{1,1,1,1,2,2,2,2,2};
    int k = 2;
    n = nums.size(); */
    int sum = 0;
    for(auto &x : nums){
    	sum += x;
    }
    int k = 4;\
   /* if(sum % k != 0)
    	return false;*/
   /* int target = sum / k;
    cout<<func(nums,0,k,0,target)<<"\n";*/

    n = nums.size();
    memset(dp,-1,sizeof dp);
    cout<<func(0,0,sum/k,k,0)<<"\n";
    cout<<dp[(1<<n)- 1]<<"\n";
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