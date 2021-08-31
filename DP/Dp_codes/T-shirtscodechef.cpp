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

int ALL_PERSONS;
int dp[1025][102];
vector<vector<int> > v;
int cal(int mask,int pos){
	if(mask == ALL_PERSONS){
		return 1;
	}
	if(pos == 101){
		return 0;
	}
	if(dp[mask][pos] != -1){
		return dp[mask][pos];
	}
	int ans = 0;
	ans = cal(mask,pos+1);

	for(auto p : v[pos]){
		if((mask & (1<<p)) == 0){
			ans =  (ans % mod + cal((mask|(1<<p)),pos+1) % mod)%mod;
		}
	}
	return dp[mask][pos] = ans;
}
int stoi(string &s){
	stringstream ss(s);
	int x;
	ss>>x;
	return x;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    v.reserve(110);
    w(x){
    	memset(dp,-1,sizeof(dp));
    	int n; 
    	cin >> n;

    	ALL_PERSONS = (1<<n) - 1;
    	string s;
    	for(int i=0;i<=100;i++){
    		v[i].clear();
    	}
    	cin.get();
    	for(int i=0;i<n;i++){
    		getline(cin,s);
    		stringstream ss(s);
    		string temp;
    		while(ss>>temp){
    			v[stoi(temp)].push_back(i);
    		}
    	}
    	cout<<cal(0,1)<<"\n";
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