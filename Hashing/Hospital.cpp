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
	(..., (cout << delim << values, delim = ", "));
}

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> g[100005];

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	vi A {0, 1, 1, 3, 0};
	vi B {1, 2, 3, 4, 5};
	vi H {2, 4};
	int n = A.size();

	rep(i, 0, n) {
		g[A[i]].pb(B[i]);
		g[B[i]].pb(A[i]);
	}

	queue<pair<int, int>> q;
	int N = H.size();
	vector<int> visited(n + 1, 0);
	rep(i, 0, N) {
		q.push({H[i], 0});
	}
	int ans = -1;
	while (!q.empty()) {
		auto [node, dist] = q.front();
		q.pop();
		ans = max(ans, dist);

		visited[node] = 1;

		for (auto ch : g[node]) {
			if (!visited[ch]) {
				int chDist = dist + 1;
				q.push({ch, chDist});
			}
		}
	}
	cout << ans << "\n";
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