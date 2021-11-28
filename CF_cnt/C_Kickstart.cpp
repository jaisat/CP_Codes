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
    if (n == 1) {
        cout << s << "\n";
        return;
    }

    string modi = "";
    rep(arb, 0, 105) {
        rep(i, 0, 10) {
            char ch1 = char(i + '0');
            char ch2 = char((i + 1 ) % 10 + '0');
            char rep = char((i + 2) % 10 + '0');
            modi += s[0];
            char prev = s[0];
            for (int j = 1; j < (int)s.size(); j++) {
                //modi += s[j];
                if (s[j] == ch2 and prev == ch1) {
                    modi.pop_back();
                    modi += rep;
                    prev = rep;
                } else {
                    modi += s[j];
                    prev = s[j];
                }
            }
            // deb(modi);
            s = modi;
            modi = "";
        }
    }
    cout << s << "\n";
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