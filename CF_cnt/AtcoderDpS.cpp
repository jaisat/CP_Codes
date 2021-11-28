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

int n, d;
string str;
int dp[10005][2][100];

int count_digits(int pos, int f, int sum) {
	if (pos == n) {
		return sum == 0;
	}

	if (dp[pos][f][sum] != -1) {
		return dp[pos][f][sum];
	}

	int ans = 0;
	int no = str[pos] - '0';
	if (!f) {
		rep(i, 0, no) {
			ans += count_digits(pos + 1, 1, (sum + i) % d);
			ans %= mod;
		}

		ans += count_digits(pos + 1, 0, (sum + no) % d);
		ans %= mod;
	} else {
		rep(i, 0, 10) {
			ans += count_digits(pos + 1, 1, (sum + i) % d);
			ans %= mod;
		}
	}
	return dp[pos][f][sum] = ans;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> str;
	cin >> d;
	n = str.size();
	memset(dp, -1, sizeof dp);
	cout << (count_digits(0, 0, 0) - 1 + mod) % mod << "\n";
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