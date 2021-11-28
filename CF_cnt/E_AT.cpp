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

int find(int i, vi & parent) {
	if (parent[i] == i) {
		return i;
	}
	return find(parent[i], parent);
}

void Union(int a, int b, vi &parent) {
	int p1 = find(a, parent);
	int p2 = find(b, parent);

	if (p1 != p2)
		parent[b] = a;

}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	rep(i, 0, m) {
		int v, u;
		cin >> u >> v;
		g[v].pb(u);
		g[u].pb(v);
	}

	vi parent(n + 1);
	rep(i, 1, n + 1) {
		parent[i] = i;
	}

	vi ans_v = {0};
	int ans = 0;
	for (int i = n; i > 1; i--) {
		ans++;
		for (auto ch : g[i]) {
			if (ch < i ) {
				continue;
			}
			if (find(i, parent) != find(ch, parent)) {
				Union(i, ch, parent);
				ans--;
			}
		}
		ans_v.pb(ans);
	}
	reverse(ans_v.begin(), ans_v.end());
	rep(i, 0, (int)ans_v.size()) {
		cout << ans_v[i] << "\n";
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