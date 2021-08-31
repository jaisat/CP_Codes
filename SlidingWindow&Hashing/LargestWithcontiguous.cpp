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
    int n;
    cin >> n;
    vi arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    int min_i = INT_MAX;
	int max_i = INT_MIN;	
	int ans = 0;


	for(int i=0;i<n;i++){
	    unordered_set<int> s;
		for(int j=i;j<n;j++){
		   if(s.find(arr[j]) != s.end()){
		      break;
		   } 
		    s.insert(arr[j]);
			min_i = min(min_i,arr[j]);
			max_i = max(max_i,arr[j]);
			if(max_i - min_i == j - i){
				ans = max(ans,j - i + 1);
			}
		}

   	 min_i = INT_MAX;
	 max_i = INT_MIN;
		s.clear();
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