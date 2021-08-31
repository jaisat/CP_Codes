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
 
vi v{1,1,1,1,1,1,1,1};
int n;
bool func(int mid,int sum){
	int sub_sum = 0;
	for(int i = 0; i < n; i++){
		sub_sum += v[i];
		if(i >= mid){
			sub_sum -= v[i - mid];
		}
		if(sub_sum >= sum)
			return true;		
	}
	return false;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int sum;
    cin >> sum;
    n = v.size();
    int s = 1;
    int e = n;
    int ans = -1;
    while(s <= e){
    	int mid = (s + e) / 2;
    	if(func(mid,sum)){
    		ans = mid;
    		e = mid - 1;
    	}else{
    		s = mid + 1;
    	}
    }
    return ans == -1 ? 0 : ans;
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