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
#define all(x)            x.begin(), x.end()
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

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> color[3];
    color[0].resize(n + 2, 0);
    color[1].resize(n + 2, 0);
    color[2].resize(n + 2, 0);
    s = '*' + s;
    rep(i, 1, n + 1) {
        if (s[i] == 'U')
            continue;
        if (s[i] == 'R' || s[i] == 'O' || s[i] == 'P' || s[i] == 'A') {
            color[0][i] = 1;
        }
        if (s[i] == 'Y' || s[i] == 'G' || s[i] == 'O' || s[i] == 'A') {
            color[1][i] = 1;
        }

        if (s[i] == 'B' || s[i] == 'P' || s[i] == 'G' || s[i] == 'A') {
            color[2][i] = 1;
        }
    }

    int ans = 0;

    rep(i, 1, n + 1) {
        if (color[0][i]) {
            if (color[0][i - 1] == 0)
                ans++;
        }

        if (color[1][i]) {
            if (color[1][i - 1] == 0)
                ans++;
        }

        if (color[2][i]) {
            if (color[2][i - 1] == 0)
                ans++;
        }
    }

    cout << ans << "\n";

}

int32_t main()
{
    clock_t begin = clock();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tt;
    cin >> tt;
    for (int T = 1; T <= tt; T++) {
        cout << "Case #" << T << ": ";
        c_p_c();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}