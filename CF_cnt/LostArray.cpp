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

int dp[200005][3];
int n0, n1, n2, n;

int noofways(int pos, int mo) {
	if (pos == n) {
		return mo == 0;
	}

	int &ans = dp[pos][mo];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	ans = ans + n0 * noofways(pos + 1, mo);
	ans %= mod;
	ans = ans + n1 * noofways(pos + 1, (mo + 1) % 3);
	ans %= mod;
	ans = ans + n2 * noofways(pos + 1, (mo + 2) % 3);
	ans %= mod;

	return ans;
}
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int l, r;
	cin >> n >> l >> r;

	n0 = r / 3;
	n1 = n0;
	n2 = n0;
	if (r % 3 == 1) {
		n1++;
	} else if (r % 3 == 2) {
		n1++;
		n2++;
	}

	int nl1, nl2;
	int nl0 = (l - 1) / 3;
	nl1 = nl0;
	nl2 = nl0;
	if ((l - 1) % 3 == 1) {
		nl1++;
	} else if ((l - 1) % 3 == 2) {
		nl1++;
		nl2++;
	}

	n0 -= nl0;
	n1 -= nl1;
	n2 -= nl2;


	memset(dp, -1, sizeof dp);
	int ans = noofways(0, 0);
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