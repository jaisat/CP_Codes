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
#define all(x)			x.begin(), x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << vars << " = ";
	string delim = "";
	(..., (cout << delim << values << "\n"));
}

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 2e5 + 5;
vector<int> g[N];

int find(int i, vi &parent) {
	if (parent[i] == -1 ) {
		return i;
	}
	return parent[i] = find(parent[i], parent);
}

void union_set(int x, int y, vi &parent, vi &rank) {

	int s1 = find(x, parent);
	int s2 = find(y, parent);

	if (s1 != s2) {
		if (rank[s1] > rank[s2]) {
			parent[s2] = s1;
			rank[s1] += rank[s2];
		} else {
			parent[s1] = s2;
			rank[s2] += rank[s1];
		}
	}
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	w(x) {

		int n, m;
		cin >> n >> m;
		if (m == 0) {
			cout <<  n - 1 << "\n";
			continue;
		}
		vi parent(n + 1, -1);
		vi rank(n + 1, 1);

		rep(i, 0, m) {
			int u, v;
			cin >> u >> v;
			union_set(u, v, parent, rank);
		}

		rep(i, 1, n) {
			g[find(i, parent)].pb(find(i + 1, parent));
			g[find(i + 1, parent)].pb(find(i, parent));
		}

		auto bfs = [&](int src, int dest)->int{
			vi vis(n + 1, 0);
			queue<pii> q;
			q.push({src, 0});

			while (!q.empty()) {
				auto [ curr, dist ] = q.front();
				q.pop();

				if (curr == dest) {
					return dist;
				}
				vis[curr] = 1;
				for (auto ch : g[curr]) {
					if (!vis[ch]) {
						q.push({ch, dist + 1});
					}
				}

			}
			return INT_MAX;
		};

		cout << bfs(find(1, parent), find(n, parent)) << "\n";

		rep(i, 0, N) {
			g[i].clear();
		}
	}
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