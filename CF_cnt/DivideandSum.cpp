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
#define mod             998244353
#define inf             1e18
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 300005;
int fact[N];

int pw(int a, int b, int m) {
	if (b == 0)
		return 1;

	int ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
			ans %= m;
		}
		a *= a;
		a %= m;
		b = b >> 1;
	}
	return ans;
}

int inverse(int a, int m) {
	return pw(a, m - 2, m);
}
int ncr(int n, int r) {
	int ans = (fact[n] * inverse(fact[r], mod)) % mod * inverse(fact[n - r], mod);
	ans %= mod;
	return ans;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fact[0] = 1;
	rep(i, 1, N) {
		fact[i] = i * fact[i - 1];
		fact[i] %= mod;
	}
	int n;
	cin >> n;
	vector<int> arr(2 * n);
	rep(i, 0, 2 * n) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	rep(i, 0, n) {
		ans -= arr[i];
	}
	rep(i, n, 2 * n) {
		ans += arr[i];
	}

	ans %= mod;
	cout << ans * ncr(2 * n, n) % mod << "\n";
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