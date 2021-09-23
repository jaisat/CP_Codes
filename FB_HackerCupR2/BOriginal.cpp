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


void c_p_c()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	if (n + m - 1 > a || n + m - 1 > b) {
		cout << "Impossible";
		return;
	}

	vector<vector<int>> grid(n, vector<int>(m, 1000));
	if (n == 2 and m == 2) {
		rep(x, 1, 1000) {
			rep(y, 1, 1000) {
				int z1 = a - (x + y);
				int z2 = b - (x + y);
				if (y < z2 and x < z1 and z1 > 0 and z2 > 0) {
					cout << "Possible" << '\n';
					grid[0][0] = x;
					grid[0][1] = y;
					grid[1][0] = z2;
					grid[1][1] = z1;
					rep(i, 0, n) {
						rep(j, 0, m) {
							cout << grid[i][j] << " ";
						}
						cout << "\n";
					}
					return;
				}
			}
		}
		cout << "Impossible" << "\n";
		return;
	}

	rep(i, 0, m) {
		grid[0][i] = 1;
	}

	rep(i, 0, n - 1) {
		grid[i][m - 1] = 1;
	}

	grid[n - 1][m - 1] = a - (n + m - 2);

	rep(i, 0, n) {
		grid[i][m - 2] = 1;
	}
	rep(i, 1, m - 2) {
		grid[n - 1][i] = 1;
	}

	grid[n - 1][0] = b - (n + m - 2);

	cout << "Possible" << "\n";
	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}

int32_t main()
{
	clock_t begin = clock();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	w(x) {
		cout << "Case #" << t << ": ";
		c_p_c();
		t++;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	//cout << "Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}