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

string func(string a) {
	a.push_back('0');
	reverse(all(a));
	while (a[0] == '0') {
		reverse(all(a));
		a.pop_back();
		reverse(all(a));
	}
	return a;
}

bool canmake(string a, string b) {
	int n = a.size();
	int m = b.size();

	for (int i = 0; i + n - 1 < m; i++) {
		string sub = b.substr(i, n);
		int found = 1;
		if (sub != a) {
			continue;
		} else {
			rep(j, 0, i) {
				if (b[j] != '1') {
					found = 0;
				}
			}
			rep(j, i + n, m) {
				if (b[j] != '1') {
					found = 0;
				}
			}
			if (found) {
				return 1;
			}
		}
	}
	return 0;
}
void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << "YES" << "\n";
		return;
	}

	string a = "", b = "";
	rep(i, 0, 62) {
		if (x & (1LL << i)) {
			a += '1';
		} else {
			a += '0';
		}

		if (y & (1LL << i )) {
			b += '1';
		} else {
			b += '0';
		}
	}

	reverse(all(a));
	while (a[0] == '0') {
		reverse(all(a));
		a.pop_back();
		reverse(all(a));
	}
	reverse(all(b));
	while (b[0] == '0') {
		reverse(all(b));
		b.pop_back();
		reverse(all(b));
	}

	if (a == b) {
		cout << "YES" << "\n";
		return;
	} else if (b.back() == '0') {
		cout << "NO" << "\n";
		return;
	}

	string newA = a;
	string newB = func(a);

	if (canmake(newA, b) || canmake(newB, b)) {
		cout << "YES" << "\n";
		return;
	}

	reverse(all(newA));
	reverse(all(newB));

	if (canmake(newA, b) || canmake(newB, b)) {
		cout << "YES" << "\n";
		return;
	}
	cout << "NO" << "\n";
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