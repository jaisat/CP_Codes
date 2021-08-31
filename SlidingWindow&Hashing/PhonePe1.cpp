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
int n;
bool isValid(int x,int y,set<pair<int,int>> &visited){
	if(x < 0 || y < 0 || x >= n || y >= n || visited.find({x,y}) != visited.end())
		return false;
	return true;
}

bool dfs(int x,int y,vector<vector<int>> &grid,int cost,set<pair<int,int>> &visited){
	visited.insert({x,y});
	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	if(x == n-1 and y == n-1){
		return true;
	}

	for(int k=0;k<4;k++){
		int nx = x + dx[k];
		int ny = y + dy[k];

		if(isValid(nx,ny,visited) and grid[nx][ny] <= cost){
			bool sub = dfs(nx,ny,grid,cost,visited);
			if(sub)
				return true;
		}
	}
	return false;
} 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<int> > grid = {{0,2},{1,3}};
    set<pair<int,int> > visited;
    n = grid.size();

    int s = max(grid[0][0],grid[n-1][n-1]);
    int e = n *n - 1;
 
    int ans = 0;
    while(s <= e){
 
    	int mid =  s + (e -s) / 2;
    	if(dfs(0,0,grid,mid,visited)){

    		e = mid - 1;
    		ans = mid;
    	}else{
    		s = mid + 1;
    	}
    	visited.clear();
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