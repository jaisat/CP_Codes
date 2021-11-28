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

int dp[2005][2005][2];
int m, d;
string str;
int countMagic(int pos, int mo, int small) {
	if (pos == str.size()) {
		return (mo == 0);
	}

	int &ans = dp[pos][mo][small];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	int curr = str[pos] - '0';

	if (pos & 1) {
		if (small) {
			ans += countMagic(pos + 1, (mo * 10 + d) % m, 1);
			ans %= mod;
		} else {
			if (d <= curr) {
				ans += countMagic(pos + 1, (mo * 10 + d) % m, (d != curr));
				ans %= mod;
			} else {
				return 0;
			}
		}
	} else {
		rep(i, 0, 10) {
			if (i == d) {
				continue;
			}
			if (small || i < curr) {
				ans += countMagic(pos + 1, (mo * 10 + i) % m, 1);
				ans %= mod;
			} else if (i == curr) {
				ans += countMagic(pos + 1, (mo * 10 + i) % m, 0);
				ans %= mod;
			}
		}
	}
	return ans;
}

bool checkMagic(string &no) {
	int n = (int)no.size();
	int mo = 0;

	for (int i = 0; i < n; i++) {
		int curr = (no[i] - '0');
		mo = (mo * 10 + curr) % m;
	}

	int f = 1;
	rep(i, 0, n) {
		if ((i + 1) % 2 == 0) {
			if ((no[i] - '0') != d) {
				f = 0;
				break;
			}
		} else {

			if ((no[i] - '0') == d) {
				f = 0;
				break;
			}
		}
	}
	/*deb(no);
	deb(mo);
	deb(f);*/
	return ((mo == 0) and f);
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> m >> d;
	string a, b;
	cin >> a >> b;
	/*int a, b;
	cin >> a >> b;*/
	/*rep(i, a, b + 1) {
		string temp = to_string(i);
		//cout << temp << " ";
		if (checkMagic(temp, m, d)) {
			ans++;
		}
	}
	cout << ans << "\n";*/

	/*if (checkMagic(no, m)) {
		cout << "Y" << "\n";
	} else {
		cout << "N" << "\n";
	}*/
	str = b;
	memset(dp, -1, sizeof dp);
	int ansR = countMagic(0, 0, 0);
	memset(dp, -1, sizeof dp);
	str = a;
	int ansL = countMagic(0, 0, 0);
	int ans = ( ansR - ansL + mod );

	// deb(ansR);
	// deb(ansL);
	if (checkMagic(a)) {
		ans++;
	}
	ans %= mod;
	cout << ans << "\n";

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