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
#define all(x)          x.begin(), x.end()
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


void c_p_c() {
    int n, m, k;
    cin >> n >> m >> k;
    int up = 0, down = 0, to = 0;
    vector<vector<int> > grid(n, vector<int>(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            char ch;
            cin >> ch;
            if (ch == 'X')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    rep(j, 0, m) {
        if (grid[k - 1][j])
            to++;
        int f = 0;
        rep(i, 0, k - 2) {
            if (grid[i][j] == 0) {
                f = 1;
                if (i != 0)
                    up += i - 1;
                break;
            }
        }
        if (f == 0) {
            up++;
        }
    }



    rep(j, 0, m) {
        int f = 0;
        for (int i = n - 1; i > k - 1; i--) {
            if (grid[i][j] == 0) {
                f = 1;
                if (i != n - 1)
                    down += n - i - 2;
                break;
            }
        }
        if (f == 0) {
            down++;
        }

    }
    deb(up);
    deb(down);
    deb(to);

    int ans = min(up + 1, min(down + 1, to));
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
    int t = 1;
    w(x) {
        cout << "Case #" << t << ": ";
        c_p_c();
        cout << "\n";
        t++;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    //cout << "Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}