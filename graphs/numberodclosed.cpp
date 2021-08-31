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

bool isOk;

bool isvalid(int i,int j,int n,int m){
	if(i == 0 || i == n - 1 || j == 0 || j == m -1)
		isOk = 0;

	if(i < 0 || i >= n || j < 0 || j >= m){
		return false;
	}

	return true;
}
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int i,int j,int n,int m){
	vis[i][j] = true;

	for(int k = 0; k < 4; k++){
		int x = i + dx[k];
		int y = j + dy[k];

		if(isvalid(x,y,n,m) and (grid[x][y] == 0) and (vis[x][y] == 0)){
			dfs(x,y,n,m);
		}
	}

}
int func(vector<vector<int> > &grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int> > vis(n,vector<int>(m,0));
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] and grid[i][j] == 0){
				isOk = 1;
				dfs(i,j);
				cnt += isOk;
			}
		}
	}
	return cnt;

}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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