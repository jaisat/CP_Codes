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
		int n, k;
		cin >> n >> k;
		vi arr(n);
		rep(i, 0, n) {
			cin >> arr[i];
		}
		int peaks = 0;
		int ans = 0;
		int left = 0;
		rep(i, 2, n) {
			if (i < k) {
				if (arr[i] < arr[i - 1] and arr[i - 2] < arr[i - 1]) {
					peaks++;
				}
				if (peaks > ans) {
					left = 0;
					ans = peaks;
				}
			} else {
				if (arr[i] < arr[i - 1] and arr[i - 2] < arr[i - 1]) {
					peaks++;
				}

				if (arr[i - k + 2] < arr[i - k + 1] and arr[i - k ] < arr[i - k + 1]) {
					peaks--;
				}
				if (peaks > ans) {
					left = i - k + 1;
					ans = peaks;
				}
			}
		}
		cout << ans + 1 << " " << left + 1   << "\n";
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