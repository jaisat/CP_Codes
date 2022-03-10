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
	(..., (cout << delim << values, delim = ", "));
}

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool canPossible(string &s) {
	vector<int> occ(26, 0);
	for (auto ch : s) {
		occ[ch - 'a']++;
	}
	int oddCount = 0;
	for (auto f : occ) {
		if (f & 1) {
			oddCount++;
		}
	}
	return oddCount <= 1;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	w(x) {
		string s;
		cin >> s;
		if (!canPossible(s)) {
			cout << "Impossible" << "\n";
			return;
		}

		int start = 0;
		int ans = 0;
		int n = (int)s.size();
		int end = n - 1;
		while (start < end) {
			if (s[start] == s[end]) {
				start++;
				end--;
			} else {
				int j = end - 1;
				while ( j > start and s[j] != s[start]) {
					j--;
				}
				if (j == start) {
					swap(s[start], s[start + 1]);
					ans++;
				} else {
					for (int k = j; k < end; k++) {
						swap(s[k], s[k + 1]);
						ans++;
					}
					start++;
					end--;
				}
			}
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