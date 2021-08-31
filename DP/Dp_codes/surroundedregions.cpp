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

int m,n;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
bool isvalid(int x,int y){
	if(x < 0 || x >= m || y < 0 || y >= n){
		return false;
	}
	return true;
}
void dfs(int i,int j,vector<vector<char>> &board){
	board[i][j] = '#';
	for(int k=0;k<4;k++){
		int x = i + dx[k];
		int y = j + dy[k];
		if(isvalid(x,y) and board[x][y] == 'O')
			dfs(x,y,board);
	}
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vector<char>> board;
    m = board.size();
    n = board[0].size();
 	for(int i =0;i<m;i++){
 		if(board[i][0] == 'O'){
 			dfs(i,j,board);
 		}
 		if(board[i][n-1] == 'O'){
 			dfs(i,j,board);
 		}
 	}
 	 for(int j =0;j<n;j++){
 		if(board[0][j] == 'O'){
 			dfs(i,j,board);
 		}
 		if(board[m-1][j] == 'O'){
 			dfs(i,j,board);
 		}
 	}


 	for(int i=0;i<m;i++){
 		for(int j=0;j<n;j++){
 			if(board[i][j] == '#'){
 				board[i][j] = 'O';
 			}else if(board[i][j] = 'O'){
 				board[i][j] = 'X';
 			}
 		}
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