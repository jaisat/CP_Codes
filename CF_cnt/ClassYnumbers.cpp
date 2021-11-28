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

int dp[20][20][2];
int classy(int pos, int no, int small, string &str) {
	if (pos == (int)str.size()) {
		return (no <= 3);
	}

	if (dp[pos][no][small] != -1) {
		return dp[pos][no][small];
	}

	int curr = str[pos] - '0';
	int ans = 0;
	rep(i, 0, 10) {
		if (small || i < curr) {
			if (i == 0) {
				ans += classy(pos + 1, no, 1, str);
			} else {
				ans += classy(pos + 1, no + 1, 1, str);
			}
		} else if (i == curr) {
			if (i == 0) {
				ans += classy(pos + 1, no, 0, str);
			} else {
				ans += classy(pos + 1, no + 1, 0, str);
			}
		}
	}
	return dp[pos][no][small] = ans;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		int L, R;
		cin >> L >> R;
		L--;
		string l, r;
		l = to_string(L);
		r = to_string(R);
		memset(dp, -1, sizeof dp);
		int ansR = classy(0, 0, 0, r);
		memset(dp, -1, sizeof dp);
		int ansL = classy(0, 0, 0, l);

		cout << ansR - ansL << "\n";
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