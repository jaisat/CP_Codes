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
int n;
vector<vector<int> > arr;
int solve(){
	int maxv = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] && i && j){
				arr[i][j] = 1 + min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]});
				
			}
			maxv = max(maxv,arr[i][j]);
		}
	}
	return maxv;
}
int countsuchsquares(){
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] && i && j){
				arr[i][j] = 1 + min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]});
			}
			res += arr[i][j];
		}
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
    cin >> n;
    arr.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++)
    		cin >> arr[i][j];
    }
    cout<<solve()<<"\n";
    cout<<countsuchsquares()<<"\n";
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