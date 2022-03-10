#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
/*#define mp              make_pair*/
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
string s;
int p, q;
int dp[100005][2];
map<pair<int, pair<string, int> >, int > mp;
int find(int i, int X, int Y, int axis) {
	if (i == n) {
		if (X == p and Y == q) {
			return 1;
		} else {
			return 0;
		}
	}

	if (dp[i][axis] != -1) {
		return dp[i][axis];
	}
	/*string xstr = to_string(X);
	string ystr = to_string(Y);
	string nstr = xstr + '_' + ystr;
	if (mp.find({i, {nstr, axis}}) != mp.end()) {
		return mp[ {i, {nstr, axis}}];
	}*/

	int ans;
	if (s[i] == '1') {
		if (axis) {
			ans  = find(i + 1, X + 1, Y, axis) || find(i + 1, X - 1, Y, axis);
		} else {
			ans  = find(i + 1, X, Y + 1, axis) || find(i + 1, X, Y - 1, axis);
		}
	} else {
		if (axis) {
			ans = find(i + 1, X, Y + 1, !axis) || find(i + 1, X, Y - 1, !axis);

		} else {
			ans = find(i + 1, X + 1, Y, !axis) || find(i + 1, X - 1, Y, !axis);
		}
	}

	return /*mp[ {i, {nstr, axis}}] =*/ dp[i][axis] =  ans;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		cin >> n;
		cin >> p >> q;
		cin >> s;

		memset(dp, -1, sizeof dp);
		int f = find(0, 0, 0, 0) || find(0, 0, 0, 1);

		if (f) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
		mp.clear();
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