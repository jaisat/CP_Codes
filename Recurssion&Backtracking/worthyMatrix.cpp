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
    	int A[n][m];
    	int val = 0;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++)
    			cin >> A[i][j];
    	}
    	int max_dim = min(n,m);
    	int l = 0;
    	while(l < max_dim){
    		l++;
    		if(l == 1){
    			for(int i=0;i<n;i++){
    				for(int j=0;j<m;j++){
    					if(A[i][j] >= k ) val = val +1;
    				}
    			}
    		}else{
    			for(int i=0;i<n;i++){
    				for(int j=0;j<m;j++){
    					int sum = 0;
    					for(int k=j;k<j+l;k++){
    						for(int p=i;p<i+l;p++){
    							sum += A[p][k];
    						}
    					}
    					double avg = (double)sum/l*l;
    					if(avg >=k){
    						val = val + m - l + 1 - j;
    						break;
    					}
    				}
    			}
    		}
    	}
    	cout<<val<<endl;
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}