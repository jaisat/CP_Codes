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
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
vector<int> compute_Lps(string s){
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    int i = 1,j = 0;
    while( i < n){
        if(s[i] == s[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }else{
            if(j == 0){
                lps[i++] = 0;
            }else{
                j = lps[j - 1];
            }
        }
    }
    return lps;
}

vector<int> KMP(string text,string pattern){
  /*  string text,pattern;
    cin >> text >> pattern;*/

    string good = pattern + "#" + text;
    vector<int> occ;
    vector<int> lps = compute_Lps(good);
    for(int i = pattern.size() + 1; i < good.size(); i++){
        if(lps[i] == pattern.size()){
            occ.pb(i - pattern.size() + 1 - (pattern.size() + 1));
        }
    } 
   /* for(auto x : occ)
        cout<<x<<" ";*/
   // cout<<"\n";

    return occ;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string text,prefix,suffix;
    cin >> text >> prefix >> suffix;
    vector<int> lpssuffix,lpsprefix;

    for(int i=0;i<prefix.size();i++){
        string sub = prefix.substr(i,prefix.size()-i+1);
        lpsprefix = KMP(text,sub);
        if(lpsprefix.size() != 0){
            break;
        }
    }
    int sz = 0;
    for(int i=suffix.size()-1;i>=0;i--){
        string sub = suffix.substr(0,i+1);
        lpssuffix = KMP(text,sub);
        if(lpssuffix.size() != 0){
            sz = i;
            break;
        }
    }

    for(auto x : lpsprefix)
        cout<<x<<" ";
    cout<<"\n";
    for(auto x : lpssuffix)
        cout<<x<<" ";  

    set<string> s;
    int n = lpsprefix.size();
    int m = lpssuffix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int idxi = lpsprefix[i];
            int idxj = lpssuffix[j] + sz;
            if(idxj - idxi >= 0){
              string sub = text.substr(idxi,idxj - idxi + 1);
              s.insert(sub);
            }
        }
    }

    cout<<"\n";
    string ans = *(s.begin());
    cout<<ans<<"\n";
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}