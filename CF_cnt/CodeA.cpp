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

int dp[11][11][11];

int sz;
int count(int i, int prev, int prepre, int &ans) {
	if (i == sz) {
		return 0;
	}
	if (dp[i][prev][prepre] != -1) {
		return dp[i][prev][prepre];
	}


	for (int j = 0; j <= 2; j++) {
		if ((prev < j and prepre > prev) || (prev > j and prepre < prev)) {
			ans += 1 + count(i + 1, j, prev, ans);
		} else {
			ans += count(i + 1, j, prev, ans);
		}
	}
	return /*dp[i][prev][prepre] = */ans;

}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	w(x) {
		int n;
		cin >> n;
		int fin = 0;
		for (int j = 3; j <= n; j++) {

			memset(dp, -1, sizeof dp);
			sz =  j;
			int ans = 0;
			fin += count(2, 0, 1, ans);
			ans = 0;
			fin += count(2, 0, 2, ans);
			ans = 0;
			fin += count(2, 1, 0, ans);
			ans = 0;
			fin += count(2, 1, 2, ans);
			ans = 0;
			fin += count(2, 2, 0, ans);
			ans = 0;
			fin += count(2, 2, 1, ans);

			fin += ans;

		}
		cout << fin << "\n";

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