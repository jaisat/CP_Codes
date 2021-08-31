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
    string str;
    cin >> str;

    unordered_map<char,int> mp;


    int start = 0;
    int ans = INT_MIN;
    int n = str.size();
    /* for(int i=0;i<n;i++){
    	mp[str[i]]++;

    	while(mp.size() < i - start + 1 and start < n){
    		mp[str[start]]--;
    		if(mp[str[start]] == 0)
    			mp.erase(str[start]);
    		start++;
    	}

    	if(mp.size() == i - start + 1){
    		ans = max(ans,i - start + 1);
    	}
    }
    cout<<ans<<"\n";*/

   
    for(int end = 0; end < n; end++){
    	if(mp.find(str[end]) != mp.end()){
    		start = max(start,mp[str[end]]+1);
    	}

    	mp[str[end]] = end;
    	ans = max(ans,end - start + 1);
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