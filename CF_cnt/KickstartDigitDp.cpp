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
#define deb(x)          cout << #x << "=" << x << " "
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

int count_boring(int pos, int f, int par, int noZ, string &str) {
	if (pos == (int)str.size()) {
		// deb(pos);
		// deb(f);
		// deb(par);
		// deb(noZ);
		// cout<<"\n";

		return par == 1 and (noZ != pos);
	}
	if (dp[pos][f][par][noZ] != -1) {
		return dp[pos][f][par][noZ];
	}

	int curr = str[pos] - '0';
	int ans = 0;
	if (!f) {
		rep(i, 0, curr) {
			int f1 = ((pos - noZ + 1) & 1) and (i & 1);
			int f2 = ((pos - noZ + 1) % 2 == 0) and (i % 2 == 0);

			if (i == 0) {
				if (noZ == pos) {
					ans += count_boring(pos + 1, 1, 1, noZ + 1, str);
				} else {
					if (f1 or f2) {
						ans += count_boring(pos + 1, 1, par, noZ, str);
					} else {
						ans += count_boring(pos + 1, 1, 0, noZ, str);
					}
				}
			} else {
				if (f1 or f2) {
					ans += count_boring(pos + 1, 1, par, noZ, str);
				} else {
					ans += count_boring(pos + 1, 1, 0, noZ, str);
				}
			}

			/*if (f1 or f2) {
				if (noZ == pos and i == 0) {
					ans += count_boring(pos + 1, 1, par, noZ + 1, str);
				} else {
					ans += count_boring(pos + 1, 1, par, noZ, str);
				}
			} else {
				if (noZ == pos and i == 0) {
					ans += count_boring(pos + 1, 1, par, noZ + 1, str);
				} else {
					ans += count_boring(pos + 1, 1, 0, noZ, str);
				}
			}*/
		}
		int f1 = ((pos - noZ + 1) & 1) and (curr & 1);
		int f2 = ((pos - noZ + 1) % 2 == 0) and (curr % 2 == 0);

		if (curr == 0) {
			if (noZ == pos) {
				ans += count_boring(pos + 1, 0, 1, noZ + 1, str);
			} else {
				if (f1 or f2) {
					ans += count_boring(pos + 1, 0, par, noZ, str);
				} else {
					ans += count_boring(pos + 1, 0, 0, noZ, str);
				}
			}
		} else {
			if (f1 or f2) {
				ans += count_boring(pos + 1, 0, par, noZ, str);
			} else {
				ans += count_boring(pos + 1, 0, 0, noZ, str);
			}
		}



		/*	if (f1 or f2) {
				if (noZ == pos and curr == 0) {
					ans += count_boring(pos + 1, 0, par, noZ + 1, str);
				} else {
					ans += count_boring(pos + 1, 0, par, noZ, str);
				}
			}

			else {
				if (noZ == pos and curr == 0) {
					ans += count_boring(pos + 1, 0, par, noZ + 1, str);
				} else {
					ans += count_boring(pos + 1, 0, 0, noZ, str);
				}
			}*/



	} else {
		rep(i, 0, 10) {
			int f1 = ((pos - noZ + 1) & 1) and (i & 1);
			int f2 = ((pos - noZ + 1) % 2 == 0) and (i % 2 == 0);

			if (i == 0) {
				if (noZ == pos) {
					ans += count_boring(pos + 1, 1, 1, noZ + 1, str);
				} else {
					if (f1 or f2) {
						ans += count_boring(pos + 1, 1, par, noZ, str);
					} else {
						ans += count_boring(pos + 1, 1, 0, noZ, str);
					}
				}
			} else {
				if (f1 or f2) {
					ans += count_boring(pos + 1, 1, par, noZ, str);
				} else {
					ans += count_boring(pos + 1, 1, 0, noZ, str);
				}
			}
			/*if (f1 or f2) {
				if (noZ == pos and i == 0) {
					ans += count_boring(pos + 1, 1, par, noZ + 1, str);
				} else {
					ans += count_boring(pos + 1, 1, par, noZ, str);
				}
			}

			else {
				if (noZ == pos and i == 0) {
					ans += count_boring(pos + 1, 1, par, noZ + 1, str);
				} else {
					ans += count_boring(pos + 1, 1, 0, noZ, str);
				}
			}*/
		}
	}
	return dp[pos][f][par][noZ] = ans;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int L, R;
	cin >> L >> R;
	L--;
	string L1 = to_string(L);
	string R1 = to_string(R);
	memset(dp, -1, sizeof dp);
	int ansR = count_boring(0, 0, 1, 0, R1);
	memset(dp, -1, sizeof dp);
	int ansL = count_boring(0, 0, 1, 0, L1);
	int ans = ansR - ansL;
	deb(ans);
	deb(ansL);
	deb(ansR);

	cout << ans << "\n";

}

int32_t main()
{
	//clock_t begin = clock();
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cout << "Case #" << t << ": ";
		c_p_c();
	}


	return 0;
}