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

vi arr, seg;
int n, q;
vi buckets(1000000, 0);


void buildTree(int s, int e, int idx) {
	if (s == e) {
		seg[idx] = buckets[s];
		return;
	}

	int mid = (s + e) / 2;
	buildTree(s, mid, 2 * idx);
	buildTree(mid + 1, e, 2 * idx + 1);
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	return;
}

void update(int s, int e, int i, int val, int idx) {
	if (i < s || i > e) {
		return;
	}

	if (s == e) {
		seg[idx] = val;
		return;
	}

	int mid = (s + e) / 2;
	update(s, mid, i, val, 2 * idx);
	update(mid + 1, e, i, val, 2 * idx + 1);
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	return;
}

int query(int s, int e, int qs, int qe, int idx) {
	if (qe < s || qs > e) {
		return 0;
	}

	if ( s >= qs and e <= qe) {
		return seg[idx];
	}

	int mid = (s + e) / 2;
	int L = query(s, mid, qs, qe, 2 * idx);
	int R = query(mid + 1, e, qs, qe, 2 * idx + 1);
	return L + R;
}

int bucketNumber(int x) {
	if (x % 1000 == 0)
		x--;
	return (x / 1000);
}

int subans(int l, int h, map<int, int> &freq) {
	int res = 0;
	auto it = freq.lower_bound(l);
	while (it != freq.end() and it->first <= h) {
		res += it->second;
		it++;
	}
	return res;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> q;
	arr.resize(n);
	seg.resize(4000001);

	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
		int buck_no = bucketNumber(arr[i]);
		buckets[buck_no]++;
	}
	buildTree(0, 999999, 1);
	while (q--) {
		char type;
		cin >> type;
		if (type == '!') {
			int i, x;
			cin >> i >> x;
			int prev = arr[i - 1];
			arr[i - 1] = x;

			freq[prev]--;
			freq[x]++;

			int prevbuck = bucketNumber(prev);
			int newbuck  = bucketNumber(x);

			buckets[prevbuck]--;
			buckets[newbuck]++;


			update(0, 999999, prevbuck, buckets[prevbuck], 1);
			update(0, 999999, newbuck, buckets[newbuck], 1);

		} else {
			int a, b;
			cin >> a >> b;

			int lbuck = bucketNumber(a);
			int rbuck = bucketNumber(b);

			int ans = subans(a, min((lbuck + 1) * 1000, b), freq);
			//ans += subans(max(a, rbuck * 100 + 1), b, freq);
			ans += ((lbuck != rbuck) ? subans(max(a, rbuck * 1000 + 1), b, freq) : 0);
			ans += query(0, 999999, lbuck + 1, rbuck - 1, 1);

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