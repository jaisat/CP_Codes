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

int dp[20][2][12][2];

/*i == 0 and
z ==> 0 we have not found first active digit
-
z ==> 1 we have found first acive digit*/

int count_num(int pos, int f, int prev, int z, string &str) {
	if (pos == (int)str.size()) {
		return 1;
	}

	if (dp[pos][f][prev][z] != -1) {
		return dp[pos][f][prev][z];
	}

	int curr = str[pos] - '0';
	int ans = 0;
	if (!f) {
		rep(i, 0, curr) {
			if (i == 0) {
				if (z == 0) {
					ans += count_num(pos + 1, 1, i, 0, str);
				} else if (i != prev) {
					ans += count_num(pos + 1, 1, i, 1, str);
				}
			} else {
				if (i != prev) {
					ans += count_num(pos + 1, 1, i, 1, str);
				}
			}
		}
		if (curr == 0) {
			if (z == 0) {
				ans += count_num(pos + 1, 0, curr, 0, str);
			} else if (curr != prev) {
				ans += count_num(pos + 1, 0, curr, 1, str);
			}
		} else {
			if (curr != prev) {
				ans += count_num(pos + 1, 0, curr, 1, str);
			}
		}

	} else {
		rep(i, 0, 10) {
			if (i == 0) {
				if (z == 0) {
					ans += count_num(pos + 1, 1, i, 0, str);
				} else if (i != prev) {
					ans += count_num(pos + 1, 1, i, 1, str);
				}
			} else {
				if (i != prev) {
					ans += count_num(pos + 1, 1, i, 1, str);
				}
			}
		}
	}
	return dp[pos][f][prev][z] = ans;
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
	string L = to_string(a - 1);
	string R = to_string(b);

	memset(dp, -1, sizeof dp);
	int ansR = count_num(0, 0, 10, 0, R);
	memset(dp, -1, sizeof dp);
	int ansL = count_num(0, 0, 10, 0, L);
	if (a == 0) {
		ansL = 0;
	}
	/*	deb(ansR);
		deb(ansL);*/
	cout << ansR - ansL << "\n";
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