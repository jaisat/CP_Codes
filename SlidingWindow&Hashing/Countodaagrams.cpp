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
    if(s2.size() > s1.size())
        return;
    cout<<s1.size()<<"\n"<<s2.size();
    unordered_map<char,int> mp;
    for(auto ch : s2){
    	mp[ch]++;
    }

    vi occ;
    int start = 0;
    int n = s1.size();
    int matched = 0;
    int ans = 0;
  	for(int end = 0; end < n; end++){
  		mp[s1[end]]--;
  		if(mp[s1[end]] >= 0)
  			matched++;

  		if(end >= s2.size() - 1){
  			if(matched == s2.size()){
  				occ.pb(start);
  				ans++;
  			}
  			char left = s1[start++];
  			if(mp[left] == 0)
  				matched--;
  			mp[left]++;
  		}
  	}	
    cout<<ans<<"\n";
    for(auto x : occ)
    	cout<<x<<" ";
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