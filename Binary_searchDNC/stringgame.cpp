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
 
bool check(string str,string t,int mid,vector<int>&v){
	for(int i=0;i<mid;i++){
		str[v[i]-1] = '#';
	}
	int n = str.size();
	int m = t.size();
	int i = 0;
	int j = 0;
	while(i < n and j < m ){
		if(str[i] == t[j]){
			j++;
		}
		i++;
	}
	return j == m;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str,t;
    cin >> str >> t;
    int n = str.size();
    vi v(str.size());
    for(int i=0;i<n;i++)
    	cin >> v[i];

 
    int s = 0;
    int e = n;
    int ans = 0;
    while(s <= e){
    	int mid = (s + e) / 2;
    	if(check(str,t,mid,v)){
    		s = mid + 1;
    		ans = mid;
    	}else{
    		e = mid - 1;
    	}
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