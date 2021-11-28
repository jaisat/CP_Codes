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
	string s;
	int k;
	cin >> s >> k;
	int n = (int)s.size();
	int cnt = 0;
	rep(i, 0, s.size()) {
		if (s[i] == '.') {
			cnt++;
		}
	}
	if (k >= cnt) {
		cout << (int)s.size() << "\n";
		return;
	}

	/*  vi nextdot(n+1);
	  int prev = n;
	  for(int i=n-1;i>=0;i--){
	  	if(s[i] == '.'){
	  		nextdot[i] = prev;
	  		prev = i;
	  	}
	  }*/

	int i = 0;
	int j = 0;
	int mx  = 0;
	int ans = 0;
	int cntdot = 0;
	int prevDot = 0;
	for (; j < n; j++) {
		if (s[j] == '.') {
			cntdot++;
			while (cntdot > k) {
				//deb(j);
				if (s[i] == '.')
					cntdot--;
				i++;
			}
		}
		ans = max(ans, j - i + 1);
		//deb(ans);

	}
	cout << ans << "\n";
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