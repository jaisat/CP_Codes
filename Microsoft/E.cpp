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


bool isSorted(vector<int> arr) {
	// Array has one or no element
	int n = arr.size();
	if (n == 0 || n == 1)
		return true;

	for (int i = 1; i < n; i++)

		// Unsorted pair found
		if (arr[i - 1] > arr[i])
			return false;

	// No unsorted pair found
	return true;
}

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
		vi arr(n);

		rep(i, 0, n) {
			cin >> arr[i];
		}
		vi test = arr;

		string s;
		cin >> s;

		if (isSorted(arr)) {
			cout << 0 << "\n";
			continue;
		}

		if (s[0] != s[n - 1]) {
			cout << 1 << "\n";
			continue;
		}

		int right = n;
		int left = -1;

		rep(i, 1, n) {
			if (s[0] != s[i]) {
				right  = i;
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			if (s[i] != s[n - 1]) {
				left = i;
			}
		}

		if (right == n) {
			if (isSorted(arr)) {
				cout << 0 << "\n";
			} else {
				cout << -1 << "\n";
			}
			continue;
		}

		sort(arr.begin() + left, arr.end());
		/*rep(i,0,n){
			cout << arr[i] << " ";
		}*/
		if (isSorted(arr)) {
			cout << 1 << "\n";
			continue;
		}
		sort(test.begin(), test.begin() + right + 1);
		/*rep(i, 0, n) {
			cout << test[i] << " ";
		}*/
		if (isSorted(test)) {
			cout << 1 << "\n";
			continue;
		}

		cout << 2 << "\n";

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