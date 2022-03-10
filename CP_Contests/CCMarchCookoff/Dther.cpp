#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fi first
#define se second
typedef long long ll;
#define pb push_back
#define mp make_pair

ll ma = 998244353;

ll ce(ll n, ll k)
{
    if (n % k == 0)
        return (n / k);
    return (n / k + 1);
}

ll powl(ll a, ll b)
{
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
            ans = (ans * a) % ma;
        a = (a * a) % ma;
        b = b / 2;
    }
    return ans;
}

string n2s(ll a)
{
    string s = "";
    while (a != 0)
    {
        s = (char)(a % 10 + '0') + s;
        a = a / 10;
    }
    return s;
}

string n2b(ll a)
{
    string s = "";
    while (a != 0)
    {
        s += (char)(a % 2 + '0');
        a /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int b2n(string s)
{
    int n = s.size();
    int i;
    reverse(s.begin(), s.end());
    int ans = 0;
    int p = 1;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans += p;
        }
        p = p * 2;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        ll a[n + 1];
        ll i;
        a[1] = 1;
        cout << "1 ";
        for (i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                a[i] = 2 * a[i - 1];
            }
            else
            {
                a[i] = i;
            }
            cout << a[i] << " ";
        }
        cout << "\n";

    }

}
