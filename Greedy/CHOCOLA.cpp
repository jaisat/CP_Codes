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
    w(x){
    	int m,n;
    	cin >> m >> n;
    	int X,Y;
    	priority_queue<pair<int,int> > pq;
    	for(int i=0;i<m-1;i++){
    		cin >> X;
    		pq.push({X,1});
    	}
    	for(int i=0;i<n-1;i++){
    		cin >> Y;
    		pq.push({Y,0});
    	}

    	int c = 1,r = 1;
    	int ans = 0;
    	while(!pq.empty()){
    		auto p = pq.top();
    		pq.pop();
    		if(p.ss == 1){
    			ans += p.ff * r;
    			c++;
    		}else{
    			ans += p.ff * c;
    			r++;
    		}
    	}
    	cout<<ans<<"\n";
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