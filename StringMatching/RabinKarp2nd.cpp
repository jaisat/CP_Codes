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


int p = 31;
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
	return powr(a,mod - 2);
}

int HashFunc(string s){
	int hash = 0;
	int p_powr = 1;
	for(int i=0;i<s.size();i++){
		hash +=  p_powr * (s[i] - 'a' + 1);
		hash %= mod;
		p_powr *= p;
		p_powr %= mod;
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

    string text = "aaaaaaaaaa";
    string patt = "aa";

    int n = text.size();
    int m = patt.size();

    int prefix[n];

    for(int i=0;i<n;i++){
    	prefix[i] = (text[i] - 'a' + 1) * powr(p,i);
    	prefix[i] %= mod;
    }

    for(int i=1;i<n;i++){
    	prefix[i] += prefix[i-1];
    	prefix[i] %= mod;
    }

    int textHash = HashFunc(text.substr(0,m));
    int pattHash = HashFunc(patt);

    if(textHash == pattHash)
    	cout<<0<<"\n";

    for(int i = 1;i + m - 1 < n; i++){
    	int newHash = prefix[i+m-1] - prefix[i-1];
    	newHash += mod;
    	newHash %= mod;

    	if(newHash == (pattHash * powr(p,i)) % mod){
    		cout<< i <<"\n";
    	} 
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