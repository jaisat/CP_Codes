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
    int n,x,y,m;
    cin >> n >> m >> x >> y;
    int row =0,col=0;
    bool up = false;
    int cnt = 0;
    while(row < n and col < m){
    	if(up){
    		while(row > 0 and col < m - 1){
    			cnt+=1;
    			if(row == x and col == y){
    				return cnt;
    			}
    			//ans.pb(mat[row][col]);

    			row--;
    			col++;
    		}
    		cnt+=1;
    		if(row == x and col == y){
    			return cnt;
    		}
    		//ans.pb(mat[row][col]);
    		if(col == m-1){
    			row++;
    		}else{
    			col++;
    		}
    	}else{
    		
    		while(row < n - 1 and col > 0){
    			cnt+=1;
    			if(row == x and col == y){
    				return cnt;
    			}
    			

    			row++;
    			col--;
    		}
    		cnt+=1;
    		if(row == x and col == y){
    			return cnt;
    		}
    		
    		if(row == n-1){
    			col++;
    		}else{
    			row++;
    		}
    	}
    	up = !up;
    }

    return -1;


}
 
int32_t main()
{
    clock_t begin = clock();
   int x =  c_p_c();
   cout<<x;
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
    return 0;
}