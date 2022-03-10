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

const int N = 1e5 + 1;
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	//vector<vector<int>> mat(n,vector<int>(m));
	vector<vector<int>> r(N);
	vector<vector<int>> c(N);

	rep(i, 0, n) {
		rep(j, 0, m) {
			int X;
			cin >> X;
			r[X].pb(i);
			c[X].pb(j);
		}
	}
	rep(i, 0, N) {
		sort(all(r[i]));
		sort(all(c[i]));
	}

	int ans = 0;
	rep(i, 0, N) {
		vi rx = r[i];
		vi cx = c[i];
		int nx = (int)r[i].size();
		for (int j = 0; j < nx; j++) {
			ans += rx[j] * j + rx[j] * (nx - j - 1) * -1;
			ans += cx[j] * j + cx[j] * (nx - j - 1) * -1;
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