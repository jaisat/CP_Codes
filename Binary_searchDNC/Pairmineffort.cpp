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
#define pi    			pair<int,pair<int,int> > 
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int minEffort(vector<vector<int> > &mat){
	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int> > dist(n,vector<int>(m,INT_MAX));
	dist[0][0] = 0;
	priority_queue<pi,vector<pi>,greater<pi> > pq;
	pq.push({0,{0,0}});	
	while(pq.empty()){
		pi curr = pq.top();
		pq.pop();

		int d = curr.ff;
		int r = curr.ss.ff;
		int c = curr.ss.ss;

		if(r == n - 1 and c == m-1)
			return d;

		for(int k = 0;k < 4;k++){
			int x = r + dx[k];
			int y = c + dy[k];

			if(x < 0 || x >= n  || y < 0 || y >= m) continue;
			int nd = max(d,abs(mat[x][y] - mat[r][c]));
			if(dist[x][y] > nd){
				dist[x][y] = nd;
				pq.push({nd,{x,y}});
			}
		}	
	}
	return 0;
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