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

int n;
int dp[100005][2][12];
int cntdp[100005][2];
/*int powr(int a, int b) {
	if (b == 0) {
		return 1;
	}

	int ans = 1;
	while ( b > 0) {
		if (b & 1) {
			ans *= a;
			ans %= mod;
		}
		a = a * a;
		a %= mod;
		b = b >> 1;
	}
	return ans;
}
*/
int pows[100001];
bool done = 0;

int powr(int a, int n) {
	if (!done) {
		pows[0] = 1;
		for (int i = 1; i <= 100000; i++)
			pows[i] = (pows[i - 1] * 10LL) % mod;
		done = 1;
	}
	return pows[n];
}
int cnt(int pos, int small, string &str) {
	if (small) {
		return powr(10, n - pos);
	}
	if (pos == n) {
		return 1;
	}
	if (cntdp[pos][small] != -1) {
		return cntdp[pos][small];
	}

	int ans  = 0;
	int curr = str[pos] - '0';
	rep(i, 0, curr) {
		ans += cnt(pos + 1, 1, str);
		ans %= mod;
	}
	ans += cnt(pos + 1, 0, str);
	ans %= mod;

	return cntdp[pos][small] = ans;
}
int encoding(int pos, int small, int prev, string &str) {
	if (pos == n) {
		return 0;
	}

	if (dp[pos][small][prev] != -1) {
		return dp[pos][small][prev];
	}

	int ans = 0;
	int curr = str[pos] - '0';
	int rem = n - pos - 1;
	rep(i, 0, 10) {
		int no;
		int contri = (prev == i) ? 0 : (i * powr(10, rem));
		contri %= mod;
		if (small || i < curr) {
			no   = cnt(pos + 1, 1, str);
			ans += ((contri * no) % mod);
			ans %= mod;
			ans += encoding(pos + 1, 1, i, str);
			ans %= mod;

		} else if ( i == curr) {
			/*int no = 0;
			if (pos != n - 1) {
				string temp = str.substr(pos + 1, n - pos - 1);
				no = generate(temp);
			}*/
			no   = cnt(pos + 1, 0, str);
			ans += ((contri * no) % mod);
			ans %= mod;
			ans += encoding(pos + 1, 0, i, str);
			ans %= mod;
		}
	}
	return dp[pos][small][prev] = ans % mod;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		string L, R;
		int nL, nR;
		cin >> nL >> L;
		cin >> nR >> R;
		//cout << nL << " " << L << " " << nR << " " << R;
		n = R.size();
		memset(cntdp, -1, sizeof cntdp);
		memset(dp, -1, sizeof dp);
		int ansR = encoding(0, 0, 10, R);
		n = L.size();
		memset(cntdp, -1, sizeof cntdp);
		memset(dp, -1, sizeof dp);
		int ansL = encoding(0, 0, 10, L);


		int extra = (L[0] - '0' ) * powr(10, n - 1);
		extra %= mod;
		rep(i, 1, n) {
			if (L[i] != L[i - 1]) {
				int rem = n - i - 1;
				int contri =  (L[i - 1] - '0') * powr(10, rem);
				contri %= mod;
				extra += contri;
				extra %= mod;
			}
		}
		/*deb(ansR);
		deb(ansL);
		deb(extra);*/

		int ans = (ansR - ansL + extra + mod ) % mod;
		cout << ans << "\n";

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