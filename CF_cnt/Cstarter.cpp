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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		int n;
		cin >> n;
		vi arr(n);
		rep(i, 0, n) {
			cin >> arr[i];
		}
		vi prefix(n + 1, 0);
		vi suffix(n + 1, 0);
		prefix[0] = arr[0];

		rep(i, 1, n) {
			if (i & 1) {
				prefix[i] = prefix[i - 1] - arr[i];
			} else {
				prefix[i] = prefix[i - 1] + arr[i];
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (i & 1) {
				suffix[i] = suffix[i + 1] - arr[i];
			} else {
				suffix[i] = suffix[i + 1] + arr[i];
			}
		}

		vector<pair<int, int>>  oddmin(n + 1, {0, n});
		vector<pair<int, int>>  evenmin(n + 1, {0, n});



		int oddminsofar = INT_MAX;
		int eveminsofar = INT_MAX;
		for (int i = n - 1; i >= 0; i--) {
			if (i & 1) {
				if (oddminsofar > suffix[i]) {
					oddmin[i] = {suffix[i], i};
					oddminsofar = suffix[i];
				}
			} else {
				if (eveminsofar > suffix[i]) {
					evenmin[i] = {suffix[i], i};
					eveminsofar = suffix[i];
				}
			}
		}


		int ans = prefix[n - 1];

		rep(i, 0, n) {
			int toL   = i - 1 >= 0 ? prefix[i - 1] : 0;
			int fromR;
			int R;
			if (i & 1) {
				fromR = evenmin[i + 1].ff;
				R = evenmin[i + 1].ss;
			} else {
				fromR = oddmin[i + 1].ff;
				R = oddmin[i + 1].ss;
			}
			int k = n - ( R - i );
			int pehele = i;
			int mid = prefix[R - 1] - toL;
			int sub;
			if (pehele & 1 and k & 1) {
				sub = toL - fromR + mid;
			} else if (pehele % 2 == 0 and k % 2 == 0) {
				sub = toL - fromR + mid;
			} else {
				sub = toL - fromR - mid;
			}
			ans = max(ans, sub);
		}

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