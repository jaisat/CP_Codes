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


string l, r;
int n;
int dp[16][2];
int pow(int a, int b) {
	if (b == 0) {
		return a;
	}
	if (b == -1) {
		return 0;
	}
	int ans = 1;
	while ( b > 0) {
		if (b & 1) {
			ans *= a;
		}
		a = a * a;
		b = b >> 1;
	}
	return ans;
}
int generate(string str) {
	int ans = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		ans = ans * 10 + str[i] - '0';
	}
	return ans;
}
int digit_sum(int pos, int sml, string &str) {
	n = (int)str.size();
	if (pos >= n) {
		return 0;
	}

	if (dp[pos][sml] != -1) {
		return dp[pos][sml];
	}

	int ans = 0;
	int curr = str[pos] - '0';
	int rem = n - pos - 1;
	rep(i, 0, 10) {
		if (sml || i < curr) {
			ans += i * pow(10, rem) + digit_sum(pos + 1, 1, str);
		} else if (i == curr) {
			int no = 0;
			if (pos != n - 1) {
				string temp = str.substr(pos + 1, n - pos - 1);
				no = generate(temp);
			}
			ans += i * (no + 1) + digit_sum(pos + 1, 0, str);
		}
	}
	return dp[pos][sml] = ans;
}


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (1) {
		int a, b;
		cin >> a >> b;
		string l, r;
		if (a == -1 and b == -1) {
			break;
		}
		a--;
		l = to_string(a);
		r = to_string(b);
		memset(dp, -1, sizeof dp);
		int ansR = digit_sum(0, 0, r);
		if (b == 0) {
			ansR = 0;
		}

		memset(dp, -1, sizeof dp);
		int ansL = digit_sum(0, 0, l);
		if (a == 0) {
			ansL = 0;
		}
		int ans = ansR - ansL;
		cout << ans << "\n";

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