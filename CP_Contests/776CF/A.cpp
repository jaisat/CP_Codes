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


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	w(x) {
		string s;
		char c;
		cin >> s >> c;
		int f = 0;
		int n = s.size();
		rep(i, 0, n) {
			if (s[i] == c) {
				if ( (n - i - 1 % 2) == 0 or i % 2 == 0) {
					f = 1;
					break;
				}

			}
		}
		if (f) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
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