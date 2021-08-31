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
#define deb(x)          cout << #x << "=" << x << endl
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(x)			x.begin(), x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 

void dfs(int src,int par,int curr,multiset<int,greater<int>> &dist,vector<vector<int>> &g,vector<int> &wt){

    int flag = 1;
    for(auto ch : g[src]){
        if(ch != par){
            flag = 0;
            dfs(ch,src,curr + wt[ch],dist,g,wt);
        }
    }
    if(flag){
        dist.insert(curr);
    }

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    int t;
    cin >> t;
    for(int t1=1;t1<=t;t1++){

        int n;
        cin >> n;
        int ans;
        vector<vector<int>> g(n+1);
        vector<int> wt(n+1);    

        for(int i=1;i<=n;i++) cin >> wt[i];

        if(n == 1){
            ans = wt[1];
            cout<<"Case #"<<t1<<": "<<ans<<"\n";   
            continue;    

        }
        
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        multiset<int,greater<int> > pick;
        for(auto ch : g[1]){
            multiset<int,greater<int>> dist;
            dfs(ch,1,wt[1] + wt[ch],dist,g,wt);
            pick.insert(*(dist.begin()));
        }
        

       // int ans;

        int w1 = *(pick.begin());
        pick.erase(pick.begin());

        if(pick.size() == 0){
            ans = w1;
            cout<<"Case #"<<t1<<": "<<ans<<"\n";    
            continue;
        }
        
        int w2 = *(pick.begin());
       /* deb(w1);
        deb(w2);*/
        ans = w1 + w2 - wt[1];

        cout<<"Case #"<<t1<<": "<<ans<<"\n";    

    }
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
/*	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif */
    return 0;
}