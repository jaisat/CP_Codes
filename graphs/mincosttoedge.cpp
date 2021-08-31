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

int nextnode(int i,int j,int k,int n,int m){
	if(k == 1){
		j--;
	}else if(k == 2){
		j++;
	}else if(k == 3){
		i--;
	}else{
		i++;
	}
	if(i < 0 || i >= n || j < 0 || j >= m)
		return -1;

	return i * n + j;
}
int zeroonebfs(vector<pair<int,int> >* graph,int src,int dest,int n,int m){
	vector<int> dist(n*m,INT_MAX);
	deque<int> pq;
	dist[src] = 0;
	pq.push_back(src);

	while(!pq.empty()){
		int node = pq.front();
		pq.pop_front();

		for(auto nbr : graph[node]){
			if(dist[node] + nbr.ss 	< dist[nbr.ff]){
				dist[nbr.ff] = dist[node] + nbr.ss;

				if(nbr.ss == 0)
					pq.push_front(nbr.ff);
				else
					pq.push_back(nbr.ff);
			}
		}
	}

	return dist[dest];

}
int minCost(vector<vector<int> > &grid){
	int n = grid.size();
	int m = grid[0].size();
	vector<pair<int,int> > graph[n*m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int node = i * n + j;
			for(int k = 1; k <= 4; k++){
				int next = nextnode(i,j,k,n,m);
				if(next == -1)
					continue;
				if(k == grid[i][j]){
					graph[node].push_back({next,0});
				}else{
					graph[node].push_back({next,1});
				}
			}
		}
	}
	return zeroonebfs(graph,0,(n-1)*n + m-1,n,m);
} 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   /* vector<vector<int> > grid = {
    	{2,2,1},
    	{4,2,3},
    	{4,2,3}
    };*/
    int n,m;
    cin >> n >> m;
    vector<vector<int> > grid (n,vector<int>(m));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		int x;
    		cin >> x;
    		grid[i][j] = x;
    	}
    }
    cout<<minCost(grid)<<"\n";
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