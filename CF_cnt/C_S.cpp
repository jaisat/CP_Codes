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

		int gcd_1 = 0;
		int gcd_2 = 0;

		rep(i, 0, n) {
			if (i & 1) {
				gcd_1 = __gcd(gcd_1, arr[i]);
			} else {
				gcd_2 = __gcd(gcd_2, arr[i]);
			}
		}
		int f1 = 1;
		int f2 = 1;
		rep(i, 0, n) {
			if (i  & 1) {
				if (arr[i] % gcd_2 == 0) {
					f1 = 0;
				}
			} else {
				if (arr[i] % gcd_1 == 0) {
					f2 = 0;
				}
			}
		}
		if (f1 == 0 and f2 == 0) {
			cout << 0 << "\n";
		} else if (f1 == 0) {
			cout << gcd_1 << "\n";
		} else {
			cout << gcd_2 << "\n";
		}
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