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

int power(int a, int b) {
	int ans = 1;
	while (b > 0) {
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

int fact(int n) {
	int ans = 1;
	rep(i, 1, n + 1) {
		ans *= i;
		ans %= mod;
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
	w(x) {
		int n;
		cin >> n;
		int sub = 1;

		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}

		int h = 1;
		for (int i = 1; i <= 2 * n; i++) {
			h *= i;
			h %= mod;
		}

		int h2 = power(2, n - 1);
		int an = ((h % mod) * (power(h2, mod - 2) % mod)) % mod;

		/*ans = fact(2 * n) - sub + mod;
		ans %= mod;*/
		cout << an << "\n";
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