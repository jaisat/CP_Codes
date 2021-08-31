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
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool dfs(vector<vector<char> > *grid,int r,int c,string word,int i){
	if(i >= word.size())
		return true;

	if(r < 0 || r >= n || c < 0 || c >= m)
		return false;

	if(word[i] != grid[r][c])
		return false;

	grid[r][c] = '#';

	bool sub = false;
	for(int k=0;k<4;k++){
		int x = r + dx[k];
		int y = c + dy[k];
		sub = dfs(grid,x,y,word,i+1);
		if(sub){
			break;
		}
	}

	grid[r][c] = word[i];
	return sub;
}
bool find(vector<vector<char> > * grid,string word){
	n = grid.size();
	m = grid[0].size();
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++){
			if(word[0] == grid[i][j]){
				bool sub = dfs(grid,i,j,word,0);
				if(sub)
					return true;
			}
		}
	}
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