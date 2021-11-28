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

string str;
int n;
int dp[20][2][12][12][2][2][2];
/*int count(string &sub) {
	int ans = stoi(sub);
	return ans + 1;
}*/
int generate(string str) {
	int ans = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		ans = ans * 10 + str[i] - '0';
	}
	return ans + 1;
}
int count_pal(int pos, int small, int prev, int prevprev, int st, int ev, int odd) {
	if (pos == (int)str.size()) {
		return (ev and odd);
	}

	int &ans = dp[pos][small][prev][prevprev][st][ev][odd];
	if (ans != -1) {
		return ans;
	}


	if (ev and odd) {
		if (small) {
			return ans = pow(10, n - pos);
		} else {
			string sub = str.substr(pos, n - pos + 1);
			return ans = generate(sub);
		}
	}

	ans = 0;
	int curr = str[pos] - '0';
	rep(i, 0, 10) {
		if (small || i < curr) {
			if (i == 0 and (!st)) {
				ans += count_pal(pos + 1, 1, prev, prevprev, st, ev, odd);
			} else {
				/*	if (i == prev) and i == prevprev) {
							ans += count_pal(pos + 1, 1, i, prev, 1, 1);
					} else {
							ans += count_pal(pos + 1, 1, i, prev, 0, 1);
					}*/
				if (i == prev and i == prevprev) {
					ans += count_pal(pos + 1, 1, i, prev, 1, 1, 1);
				} else if (i == prev) {
					ans += count_pal(pos + 1, 1, i, prev, 1, 1, odd);

				} else if (i == prevprev) {
					ans += count_pal(pos + 1, 1, i, prev, 1, ev, 1);
				} else {
					ans += count_pal(pos + 1, 1, i, prev, 1, ev, odd);
				}
			}
		} else if (i == curr) {
			if (i == prev and i == prevprev) {
				ans += count_pal(pos + 1, 0, i, prev, 1, 1, 1);
			} else if (i == prev) {
				ans += count_pal(pos + 1, 0, i, prev, 1, 1, odd);

			} else if (i == prevprev) {
				ans += count_pal(pos + 1, 0, i, prev, 1, ev, 1);
			} else {
				ans += count_pal(pos + 1, 0, i, prev, 1, ev, odd);
			}
		}
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
		string a, b;
		cin >> a >> b;
		str = b;
		n = str.size();

		memset(dp, -1, sizeof dp);
		int ansR = count_pal(0, 0, 10, 11, 0, 0, 0);
		/*if (n <= 2) {
			ansR = 0;
		}*/
		//deb(ansR);
		str = a;
		n = str.size();
		memset(dp, -1, sizeof dp);
		int ansL = count_pal(0, 0, 10, 11, 0, 0, 0);
		/*if (n <= 2) {
			ansL = 0;
		}*/
		//deb(ansL);
		int ans = ansR - ansL;
		cout << ans << "\n";
		//deb(ans);
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