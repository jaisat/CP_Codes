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
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << vars << " = ";
	string delim = "";
	(..., (cout << delim << values << "\n"));
}

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

/*int dp[100];


int findMin(int i, int )*/


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif

	vi fact;
	fact.pb(6);
	for (int i = 4; i < 100; i++) {
		if (fact.back() * i > 1e12) {
			break;
		}

		fact.pb(fact.back()*i);
	}
	int k = fact.size();
	w(x) {
		int n;
		cin >> n;
		int ans = INT_MAX;
		for (int i = 0; i < (1 << k); i++) {
			int sum = 0;
			int cnt = __builtin_popcountll(i);

			for (int j = k - 1; j >= 0; j--) {
				if ((1LL << j) & i) {
					sum += fact[j];
				}
			}

			int sub = __builtin_popcountll(n - sum) + cnt;
			ans = min(ans , sub);
		}
		if (ans == INT_MAX)
			cout << -1 << "\n";
		else
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