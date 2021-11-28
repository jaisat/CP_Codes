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

int pw(int a, int b) {
	if (b == 0) {
		return 1;
	}
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b = b >> 1;
	}
	return ans;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int zc = 0;
	map<pair<int, int>, int > mp;
	rep(i, 0, n) {
		int x, y;
		cin >> x >> y;
		if (x == 0 and y == 0) {
			zc++;
			continue;
		}

		if (y < 0) {
			y *= -1;
			x *= -1;
		}

		if (y == 0) {
			x = abs(x);
		}

		int g = __gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		mp[ {x, y}]++;
	}
	int ans = 1;
	for (auto it : mp) {
		int theta = it.second;
		int xt = it.first.first;
		int yt = it.first.second;
		int xtt = -yt;
		int ytt = xt;

		if (ytt < 0) {
			xtt *= -1;
			ytt *= -1;
		}

		int thetaper = mp[ {xtt, ytt}];
		ans *= (pw(2, theta - 1) + pw(2, thetaper - 1) - 1 + mod) % mod;
		ans %= mod;
	}
	ans = (ans - 1 + zc + mod) % mod;
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