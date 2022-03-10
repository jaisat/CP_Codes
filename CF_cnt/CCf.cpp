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
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	w(x) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (n & 1) {
			cout << "NO" << '\n';
			continue;
		}
		map<char, int> freq;
		//vi freq(26,0);
		for (auto ch : s) {
			freq[ch]++;
		}
		int mx = 0;
		for (auto f : freq) {
			mx = max(mx, f.ss);
		}

		if (mx > (n / 2)) {
			cout << "NO" << "\n";
			continue;
		}
		string right = "";
		string left  = "";
		int fl;

		vector<pair<int, char>> fy;
		for (auto ch : freq) {
			fy.pb({ch.ss, ch.ff});
		}
		fl = 1;
		sort(all(fy));
		for (int i = fy.size() - 1; i >= 0; i--) {
			int fr = fy[i].ff;
			//deb(fl);
			while (fr) {
				if (fl) {
					left += fy[i].ss;
					fr--;

					if (fr == 0) {
						fl = 0;
						break;
					}
					right += fy[i].ss;
					fr--;

				} else {
					right += fy[i].ss;
					fr--;

					if (fr == 0) {
						fl = 1;
						break;

					}
					left += fy[i].ss;
					fr--;
				}

			}

		}


		string ans = "";
		//reverse(left.begin(), left.end());
		ans += left;
		ans += right;
		deb(left);
		deb(right);
		deb(ans);
		int is = 0;
		int N = (int)ans.size();
		for (int i = 0; i < N; i++) {
			if (ans[i] == ans[N - i - 1]) {
				is = 1;
				break;
			}
		}
		if (is == 1) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
			cout << ans << "\n";
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