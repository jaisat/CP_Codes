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

vector<vector<int>> visited;
vector<vector<int>> g;

map<int, map<int, set<int>>> direction;
vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
int n, m;
bool isInvalid(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == 1) {
		return true;
	}
	return false;
}

void dfs(int i, int j, int d, int &ans) {
	if (visited[i][j] == 1 and direction[i][j].count(d) == 1) {
		return;
	}

	if (!visited[i][j]) {
		ans++;
	}
	visited[i][j] = 1;
	direction[i][j].insert(d);

	int ni = i + dir[d][0];
	int nj = j + dir[d][1];

	int c = 0;
	while (c < 4 and isInvalid(ni, nj)) {
		d = (d + 1) % 4;
		ni = i + dir[d][0];
		nj = j + dir[d][1];
		c++;
	}
	if (c == 4) {
		return;
	}
	dfs(ni, nj, d, ans);
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	vector<vector<int>> mat = { {0, 0, 0, 0, 1, 0, 0} , { 1, 0, 0, 0, 0, 0, 0} , { 0, 0, 0, 0, 0, 1, 0 } , { 0, 0, 0, 0, 0, 0, 0 } };

	n = mat.size();
	m = mat[0].size();
	g = mat;

	int ans = 0;
	visited.resize(n, vector<int>(m, 0));
	dfs(0, 0, 0, ans);
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