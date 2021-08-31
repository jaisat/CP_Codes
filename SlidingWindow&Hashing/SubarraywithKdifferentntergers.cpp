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
 
int func(string &s,int k){
    int n = s.size();
	unordered_map<char,int> mp;
	int i = -1;
	int j = -1;
	int ans = 0;
	bool f1,f2;
	while(1){

		f1 = f2 = false;
		while(i < n - 1){
			f1 = 1;
			i++;
			mp[s[i]]++;
			if(mp.size() == 2){
				mp.erase(s[i]);
				i--;
				break;
			}
		}
		while(j < i){
		    f2 = 1;
			if(mp.size() == 1){
				ans += i - j;
			}
			j++;
			mp[s[j]]--;
			if(mp[s[j]] == 0)
				mp.erase(s[j]);

			if(mp.size() == 0)
				break;
		}
		
		if(f1 == 0 and f2 == 0)
		break;
	}
	return ans;

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    string s;
    int k;
    cin >> s >> k;
    int ans= 0;
    if(k == 1){
        ans = func(s,k);
        cout<<ans<<"\n";
        return;
    }
    unordered_map<char,int> smol;
	unordered_map<char,int> big;
	int is,ib,i;
	is = ib = i = -1;
	bool f1,f2,f3;
	//int ans = 0;
	int n = s.size();
	while(1){
		f1 = f2 = f3 = false;
		while(ib < n - 1){
			f1 = 1;
			ib++;
			big[s[ib]]++;
			if(big.size() == k + 1){
				big.erase(s[ib]);
				ib--;
				break;
			}
		}
		while(is < ib){
			f2 = 1;
			is++;
			smol[s[is]]++;
			if(smol.size() == k){
				smol.erase(s[is]);
				is--;
				break;
			}
		}

		while( i < is){
			f3 = 1;
			if(big.size() == k and smol.size() == k - 1)
				ans += ib - is;
			i++;
			big[s[i]]--;
			if(big[s[i]] == 0)
				big.erase(s[i]);
			smol[s[i]]--;
			if(smol[s[i]] == 0)
				smol.erase(s[i]);

			if(big.size() < k || smol.size() < k-1)
				break;
		}

		if(f1 == 0 and f2 == 0 and f3 == 0)
			break;
	}

	cout<<ans<<"\n";


}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
	// #ifndef ONLINE_JUDGE 
	//   clock_t end = clock();
	//   cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	// #endif 
    return 0;
}