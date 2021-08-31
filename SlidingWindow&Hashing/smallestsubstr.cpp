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
    string text,patt;
    cin >> text >> patt;
    int n = text.size();
    int m = patt.size();
    unordered_map<char,int> mp;
    for(auto ch : patt){
    	mp[ch]++;
    }
    int start = 0;
    int matched = 0;
    int ans = INT_MAX;
    int s_i,e_i;
    for(int end = 0; end < n; end++){
    	mp[text[end]]--;
    	if(mp[text[end]] >= 0)
    		matched++;
    	
    	while(matched == (int)patt.size()){
    	//	ans = ans(min,end - start + 1);
    		if(ans > end - start + 1){
    			s_i = start;
    			e_i = end;
    			ans = end - start + 1;
    		}
            char left = text[start++];
    		mp[left]++;
    		if(mp[left] == 1)
    			matched--;
    	}
    }

    if(ans == INT_MAX)
    	 cout<<""<<"\n";
    else
    	cout<<text.substr(s_i,e_i - s_i + 1)<<"\n";
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