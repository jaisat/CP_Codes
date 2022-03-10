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
		string a, s;
		cin >> a >> s;
		int f = 1;
		string b = "";
		int i = a.size() - 1;
		int j = s.size() - 1;

		while (i >= 0 and j >= 0) {
			if (a[i] > s[j]) {
				string newStr = "";
				if (j - 1 < 0 ) {
					f = 0;
					break;
				}
				newStr += s[j - 1];
				newStr += s[j];
				int ve = stoi(newStr);
				int added = ve - (a[i] - '0');
				if (added > 9 or added < 0) {
					f = 0;
					break;
				}

				b += char( added + '0');
				j -= 2;
				i--;
			} else {
				b += char(s[j] - a[i] + '0');
				i--;
				j--;
			}
			//deb(b);
		}

		if (i >= 0) {
			f = 0;
		}

		reverse(b.begin(), b.end());
		if (j >= 0) {
			string nst = s.substr(0, j + 1);
			nst += b;
			//deb(nst);
			b = nst;
		}


		//reverse(b.begin(), b.end());

		if (!f) {
			cout << -1 << "\n";
		} else {

			while (b[0] == '0') {
				reverse(all(b));
				b.pop_back();
				reverse(all(b));
			}

			//reverse(b.begin(), b.end());
			if (b.size() == 0) {
				b = "0";
			}
			cout << b << "\n";
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