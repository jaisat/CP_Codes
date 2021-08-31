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

double SQroot2(int n){
	double s = 0;
	double e = n;
	double ans = -1;
	int itr = 60;
	while(itr--){
		double mid = (s + e) / 2;
		if(mid * mid == n)
			return mid;
		else if(mid * mid > n){
			e = mid - 1;
		}else{
			ans = mid;
			s = mid + 1;
		}
	}
	return ans;
}
float SQroot(int n){
	int s = 0;
	int e = n;
	float ans = -1;
	while(s <= e){
		int mid = (s + e) / 2;
		if(mid * mid == n)
			return mid;
		else if(mid * mid > n){
			e = mid - 1;
		}else{
			ans = mid;
			s = mid + 1;
		}
	}

	int p = 5;

	float inc = 0.1;

	for(int timer = 1;timer <= p;timer++){

		while(ans * ans < n){
			ans += inc;
		}
		ans = ans - inc;
		inc /= 10;
	}
	return ans;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout<<SQroot2(n)<<"\n";
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