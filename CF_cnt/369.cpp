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

int dp[51][2][36][36][2];
int n;
string str;
/*
th => cnt6 - cnt3
sx => cnt9 - cnt6*/
int count(int pos, int small, int th, int sx, int f) {
	if (pos == n) {
		if (th == 17 and sx == 17 and f) {
			return 1;
		} else {
			return 0;
		}
	}
	if (th >= 36 || th < 0 || sx >= 36 || sx < 0) {
		return 0;
	}
	int &ans = dp[pos][small][th][sx][f];
	if (ans != -1) {
		return ans;
	}


	ans = 0;
	int ub = small ? 9 : str[pos] - '0';
	int curr = str[pos] - '0';
	rep(i, 0, ub + 1) {
		if (i == 3) {
			ans += count(pos + 1, !(i == ub and (!small)), th - 1, sx, 1);
			ans %= mod;
		} else if (i == 6) {
			ans += count(pos + 1, !(i == ub and (!small)), th + 1, sx - 1, f);
			ans %= mod;
		} else if (i == 9) {
			ans += count(pos + 1, !(i == ub and (!small)), th, sx + 1, f);
			ans %= mod;
		} else {
			ans += count(pos + 1, !(i == ub and (!small)), th, sx, f);
			ans %= mod;
		}
	}
	return ans;
}

bool brute(string &st) {
	int th = 0, sx = 0, ni = 0;
	rep(i, 0, st.size()) {
		if (st[i] == '3') {
			th++;
		} else if (st[i] == '6') {
			sx++;
		} else if (st[i] == '9') {
			ni++;
		}
	}
	return (th == sx and sx  == ni and th >= 1);
}
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		string a, b;
		cin >> a >> b;
		str = b;
		n = str.size();
		memset(dp, -1, sizeof dp);
		int ansR = count(0, 0, 17, 17, 0);
		str = a;
		n = str.size();
		memset(dp, -1, sizeof dp);
		int ansL = count(0, 0, 17, 17, 0);
		int extra = brute(a);
		int ans = (ansR - ansL + mod + extra) % mod ;
		/*deb(ansR);
		deb(ansL);
		deb(ans);*/
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