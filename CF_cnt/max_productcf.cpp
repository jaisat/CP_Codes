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

int dp[20][2][2][2];
int nr;
string ansstr;

/*f -> first zero*/

int maxproduct(int pos, int small, int large, int f, string &l, string &r) {
	if (pos == (int)r.size()) {

		return f;
	}

	if (dp[pos][small][large][f] != -1) {
		return dp[pos][small][large][f];
	}

	int lb = large ? 0 : l[pos] - '0';
	int ub = small ? 9 : r[pos] - '0';
	int ans = INT_MIN;
	rep(i, lb, ub + 1) {
		int sub;
		if (i == lb and i == ub) {

			if (i == 0 and (!f)) {
				sub = maxproduct(pos + 1, 0, 0, 0, l, r);
			} else {
				sub = i * maxproduct(pos + 1, 0, 0, 1, l, r);
			}
			if (sub > ans) {
				ans = sub;
				ansstr[pos] = char(i + '0');
			}
		} else if (i == lb) {
			if (i == 0 and (!f)) {
				sub = maxproduct(pos + 1, 1, 0, 0, l, r);

			} else {
				sub =  i * maxproduct(pos + 1, 1, 0, 1, l, r);

			}
			if (sub > ans) {
				ans = sub;
				ansstr[pos] = char(i + '0');
			}
		} else if (i == ub) {

			if (i == 0 and (!f)) {
				sub = maxproduct(pos + 1, 0, 0, 0, l, r);

			} else {
				sub =  i * maxproduct(pos + 1, 0, 1, 1, l, r);

			}
			if (sub > ans) {
				ans = sub;
				ansstr[pos] = char(i + '0');
			}
		} else {

			if (i == 0 and (!f)) {
				sub = maxproduct(pos + 1, 1, 0, 0, l, r);

			} else {
				sub =  i * maxproduct(pos + 1, 1, 1, 1, l, r);

			}
			if (sub > ans) {
				ans = sub;
				ansstr[pos] = char(i + '0');
			}
		}
		/*	deb(ans);
			deb(sub);*/

	}
	cout << ansstr[pos] << " ";

	return dp[pos][small][large][f] = ans;


}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	cin >> a >> b;
	string l = to_string(a);
	string r = to_string(b);

	int nl = l.size();
	nr = r.size();

	int new_sz = nr - nl;

	string n_l = "";
	rep(i, 0, new_sz) {
		n_l += '0';
	}

	n_l += l;
	deb(n_l);
	deb(r);
	ansstr.resize(nr);
	memset(dp, -1, sizeof dp);
	maxproduct(0, 0, 0, 0, n_l, r);
	cout << ansstr << "\n";




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