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
 
 
int c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int ans;

   /* priority_queue<int,vector<int>,greater<int> > pq;
    pq.push(1);
    set<int> s;

    while(!pq.empty()){
    	int m = pq.size();
    	for(int i=0;i<m;i++){
    		int top = pq.top();
    		pq.pop();
    		s.insert(top);
    		if(s.size() == n){
    			ans = *(prev(s.end()));
    			return ans;
    		}
    		pq.push(2*top);
    		pq.push(3*top);
    		pq.push(5*top);
    	}
    }
    return -1;*/

    if(n == 1)
        return 1;

   
    int a = 0,b = 0,c = 0;
    vi v(n);
    v[0] = 1;
    for(int  i=1;i<n;i++){
        v[i] = min({v[a]*2,v[b]*3,v[c]*5});
        if(v[i] == v[a]*2){
            a++;
        }
        if(v[i] == v[b]*3){
            b++;
        }
        if(v[i] == v[c]*5){
            c++;
        }
    }
    
    return v[n-1];

}
 
int32_t main()
{
    clock_t begin = clock();
    cout<<c_p_c()<<"\n";
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
    return 0;
}