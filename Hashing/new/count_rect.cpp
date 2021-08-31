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
  	set<pii> s;
    int  n;
    cin >> n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
    	int x,y;
    	cin >> x >> y;
    	v[i] = {x,y};
    }
    for(auto x : v){
    	s.insert(x);
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
    	for(int j=i+1;j<n;j++){
    		int x1 = v[i].ff;
    		int y1 = v[i].ss;
    		int x2 = v[j].ff;
    		int y2 = v[j].ss;

    		//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

    		if(x1 == x2 or y1 == y2)
    			continue;	

    		pii p1 = {x1,y2};
    		pii p2 = {x2,y1};
    		if(s.find(p1) != s.end() and s.find(p2) != s.end()){
    			ans += 1;
    		}
    	}
    }
    cout<<ans/2<<"\n";
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