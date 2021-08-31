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
 
const int p  = 31;
int powr(int a,int b){

	int res = 1;
	while(b){
		if(b & 1ll){
			res *= a;
			res %= mod;
		}
		b = b >> 1;
		a *= a;
		a %= mod;
	}
	return res;
}

int inv(int a){
	// a^-1 mod m

	return powr(a,mod-2);
}

int poly_hash_string(string s){
	int hash = 0;
	int p_powr = 1;
 
	for(int i=0;i<s.size();i++){
		hash += p_powr * (s[i] - 'a' + 1);
		p_powr *= p;
		p_powr %= mod;
		hash %= mod;
	}
	return hash;
}


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string text = "abababbaba";
    string pattern = "aba";
    int n = text.size();
    int m = pattern.size();


    int pat_hash = poly_hash_string(pattern);
    int text_hash = poly_hash_string(text.substr(0,m));

    if(pat_hash == text_hash)
    	cout<<0<<"\n";
   // cout<<pat_hash<<" "<<text_hash<<"\n";

    for(int i=1;i + m <= n;i++){
    	int new_hash = text_hash;
    	new_hash =	(new_hash - (text[i - 1] - 'a' + 1) + mod) % mod;
    	new_hash *= inv(p);
    	new_hash %= mod;
    	new_hash = new_hash + (text[i + m - 1] - 'a' + 1) * powr(p,m-1);	
    	new_hash %= mod;

    	//cout<<new_hash<<' ';
    	if(new_hash == pat_hash)
    		cout<<i<<"\n";

    	text_hash = new_hash;
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