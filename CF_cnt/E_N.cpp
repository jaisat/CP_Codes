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
		int sum = 0;
		rep(i, 0, n) {
			cin >> arr[i];
			sum += arr[i];
		}

		int f = 0;
		int sumNew = (sum * 2);
		int div = (n * (n + 1));
		if (sumNew % div) {
			f = 1;
		}
		sumNew /= div;
		if (sumNew < n) {
			f = 1;
		}
		vi ansV(n);
		vi test(n);
		rep(i, 0, n) {
			test[i] =  arr[i] - sumNew;
		}
		rep(i, 0, n) {
			if (((arr[(i - 1 + n) % n] - test[i]) % n)) {
				f = 1;
			}
			ansV[i] = (arr[(i - 1 + n) % n] - test[i]) / n;
		}
		rep(i, 0, n) {
			if (ansV[i] <= 0 || ansV[i] > 1e9) {
				f = 1;
				break;
			}
		}
		if (f) {
			cout << "NO" << "\n";
			continue;
		}

		cout << "YES" << "\n";
		rep(i, 0, n) {
			cout << ansV[i] << " ";
		}
		cout << "\n";

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