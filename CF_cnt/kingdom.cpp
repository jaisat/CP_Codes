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
#define deb(x)          cout << #x << "=" << x << endl
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

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> g[200005];
int f;
int eg;
int no;
void dfs(int src, int par, vi &vis) {
	vis[src] = true;
	no++;
	eg += g[src].size();
	for (auto ch : g[src]) {

		if (!vis[ch]) {
			dfs(ch, src, vis);
		} else if (ch != par) {
			f = 0;
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
	w(x) {
		rep(i, 0, 200005) {
			g[i].clear();
		}

		int n, m;
		cin >> n >> m;
		rep(i, 0, m) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}

		int cnt = 0;
		int x_r = 0;
		vector<int> vis(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				f = 1;
				eg = 0;
				no = 0;
				dfs(i, -1, vis);
				cnt++;
				/*deb(eg);
				deb(no);*/
				if (eg == (no) * (no - 1)) {
					x_r++;
				}
			}
		}
		if (cnt == 1) {
			cout << 0 << "\n";
			continue;
		}
		cout << x_r << '\n';
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