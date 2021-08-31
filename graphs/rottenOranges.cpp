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
 
int n,m;
int a[1000][1000];
int vis[1000][1000];

bool isvalid(int x,int y){
	if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || a[x][y] == 0)
		return false;
	return true;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> a[i][j];
    	}
    }

    queue<array<int,3>> q;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(a[i][j] == 2){
    			q.push({i,j,0});
    			vis[i][j] = 1;
    		}
    	}
    }
    int ans = 0;

    while(!q.empty()){
    	int x  	= q.front()[0];
    	int y   = q.front()[1];
    	int dis = q.front()[2];
    	q.pop();

    	ans = max(ans,dis);

    	for(int k = 0; k < 4; k++){
    		int X = x + dx[k];
    		int Y = y + dy[k];

    		if(isvalid(X,Y)){
    			vis[X][Y] = 1;
    			int newdis = dis + 1;
    			q.push({X,Y,newdis});
    		}
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