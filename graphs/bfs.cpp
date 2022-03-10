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

int N;
int visited[100006];
int dist[100006];
vector<int> g[100006];
void bfs(int src) {

	queue<int> Q;
	Q.push(src);
	memset(visited, 0, sizeof visited);
	visited[src] = true;
	dist[0] = 0;

	while (!Q.empty()) {
		int nbr = Q.top();
		Q.pop();
		for (auto nbrs : g[nbr]) {
			if (!visited[nbrs]) {
				Q.push(nbrs);
				visited[nbrs] = true;
				dist[nbrs] = dist[nbr] + 1;
			}
		}
	}
}
void spacereduced_bfs(int src) {
	queue<int> Q;
	Q.push(src);

	memset(dist, INT_MAX, sizeof dist);
	dist[src] = 0;

	while (!Q.empty()) {
		int nbr = Q.top();
		Q.pop();

		for (auto nbrs : g[nbr]) {
			if (dist[nbrs] == INT_MAX) {
				Q.push(nbrs);
				dist[nbrs] = dist[nbr] + 1;
			}
		}

	}
}


void bfs(int src) {
	queue<int> Q;
	Q.push(src);
	vi dist(N, INT_MAX);

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		for (auto nbr : g[curr]) {
			if (dist[nbr] == INT_MAX) {
				Q.push({nbr});
				dist[nbr] = dist[src] + 1;
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
	cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}