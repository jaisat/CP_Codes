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
    vector<pair<int,int> > pts = {{0,0},{1,1},{2,4}};
    int n = pts.size();
    set<pair<int,int>> s;

    long long best_dist = 1e18;

    int j = 0;
    for(int i=0;i<n;i++){
    	int d = best_dist;
    	while(pts[i].first - pts[j].first >= d){
    		s.erase({pts[j].second,pts[j].first});
    		j+=1;
    	}

    	auto it1 = s.lower_bound({pts[i].second - d,pts[i].first});
    	auto it2 = s.upper_bound({pts[i].second + d,pts[i].first});

    	for(auto it = it1; it != it2;++it){
    		int dx = pts[i].first - it->second;
    		int dy = pts[i].second - it->first;
    		best_dist = min(best_dist,1LL * dx * dx + 1LL * dy * dy);
    	}
    	s.insert({pts[i].second,pts[i].first});
    }
    cout<<best_dist<<"\n";
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