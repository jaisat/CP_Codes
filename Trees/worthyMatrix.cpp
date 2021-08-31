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
    	int n,m,k;
    	cin >> n >> m >> k;
    	double mat[n+1][m+1];
    	for(int i=0;i<=n;i++){
    		for(int j=0;j<=m;j++){
    			if(i == 0 || j == 0){
    				mat[i][j] = 0;
    			}else{
    				cin >> mat[i][j];
    			}
    		}
    	}
    	for(int i=0;i<=n;i++){
    		double pre = 0;
    		for(int j=0;j<=m;j++){
    			mat[i][j] += pre;
    			pre = mat[i][j];
    		}
    	}
    	for(int j=0;j<=m;j++){
    		double pre = 0;
    		for(int i=0;i<=n;i++){
    			mat[i][j] += pre;
    			pre = mat[i][j];
    		}
    	}
    	int zz = min(m,n);
    	int ans = 0;
    	for(int len = 1;len<=zz;len++){
    		for(int i = len;i<=n;i++){
    			for(int j=len;j<=m;j++){
    				if((mat[i][j]+mat[i-len][j-len]-mat[i-len][j]-mat[i][j-len])/(len*len)>=k){
    					ans++;
    				}
    			}
    		}
    	}
    	cout<<ans<<endl;
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