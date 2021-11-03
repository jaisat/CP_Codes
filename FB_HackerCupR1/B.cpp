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


void c_p_c()
{

	int n;
	cin >> n;
	string s;
	cin >> s;

	vi dp(n, 0);
	vi pos(n);
	int idO = -1;
	int idX = -1;
	int ans = 0;
	rep(i, 0, n) {
		if (s[i] == 'O') {
			idO = i;
			pos[i] = idX;
		} else if (s[i] == 'X') {
			idX = i;
			pos[i] = idO;
		} else {
			pos[i] = max(idX, idO);
		}
	}

	/*rep(i, 0, n) {
		cout << pos[i] << " ";
	}*/

	rep(i, 0, n) {
		int prev = pos[i];
		if (s[i] == 'F') {
			if (prev != -1) {
				int prepre = pos[prev];
				if (prepre != -1) {
					dp[i] += dp[prepre] + prepre + 1;
					dp[i] %= mod;
				}
			}
			continue;
		}
		if (prev != -1) {
			dp[i] = dp[prev] + prev + 1;
			dp[i] %= mod;
		}
	}

	rep(i, 0, n) {
		ans += dp[i];
		ans %= mod;
	}

	cout << ans << "\n";
}

int32_t main()
{
	clock_t begin = clock();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	w(x) {
		cout << "Case #" << t << ": ";
		c_p_c();
		t++;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	//cout << "Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}