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
 
// O(N^3)
vector<int> compute_lps_trivial(string s){
	int n = s.size();
	vector<int> lps(n,0);
	for(int i=0;i<s.size();i++){
		for(int len = 0; len <= i; len++){
			if(s.substr(0,len) == s.substr(i - len + 1,len))
				lps[i] = len;
		}
	}
	return lps;
}

// O(N)	
vector<int> compute_lps(string s){
	int n = s.size();
	vector<int> lps(n);
	lps[0] = 0;
	int i = 1;
	int j = 0;
	while(i < n){
		if(s[i] == s[j]){
			lps[i] = j + 1;
			i++;
			j++;
		}else{
			if(j == 0){
				lps[i++] = 0;
			}else{
				j = lps[j-1];
			}
		}
	}
	return lps;
}

vector<int> compute_LPS(string s){
	int n = s.size();
	vector<int> lps(n,0);
	lps[0] = 0;
	int i = 1;
	int j = 0;
	while(i < n){
		if(s[i] == s[j]){
			lps[i] = j + 1;
			i++;
			j++;
		}
		else{
			if(j == 0){
				lps[i++] = 0;
			}else{
				j = lps[j-1];
			}
		}
	}
	return lps;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "ababaababa";
  	vi lps =  compute_lps_trivial(s);
  	for(auto x : lps)
  		cout<<x<<" ";
  	lps =  compute_lps(s);
  	for(auto x : lps)
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