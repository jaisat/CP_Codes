#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
ll mod = 1e9+7;
vector<ll>v1(1000000,0);
ll calculate(ll arr[],ll len,ll sum)
{
    if(sum==0)
    {
        return 1;
    }
    else if(sum<0)
    {
        return 0;
    }
    if(v1[sum]!=0)
    {
        return v1[sum];
    }
    ll ans =0;
    for(ll i=0;i<len;i++)
    {
        ans += calculate(arr,len,sum-arr[i]);
        ans = ans%mod;
    }
    v1[sum] = ans%mod;
    return ans;
}
void solve()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll len,sum;
    cin>>len>>sum;
    ll arr[len];
    for(ll i=0;i<len;i++)
    {
        cin>>arr[i];
    }
    //sort(arr,arr+len);
    cout<<calculate(arr,len,sum)<<"\n";
}
int main()
{
    //fastio();
    solve();
}