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
 
int kadanes(vi &temp){
	int sum = 0;
	int maxSum = INT_MIN;
	for(int i=0;i<temp.size();i++){
		sum += temp[i];
		if(sum < 0){
			sum = 0;
		}
		maxSum = max(maxSum,sum);
	}

	for(int i=0;i<temp.size();i++){
		if(temp[i] > maxSum){
			maxSum = temp[i];
		}
	}
	return maxSum;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	int n,m;
    	cin >> n >>m;
    	vector<vi> arr(n,vi(m));
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			cin >> arr[i][j];
    		}
    	}
    	vi temp(n);
    	int res = INT_MIN;
    	for(int leftcol = 0;leftcol<m;leftcol++){
    		temp.assign(n,0);
    		for(int rightcol = leftcol;rightcol<m;rightcol++){
    			for(int i=0;i<n;i++){
    				temp[i] += arr[i][rightcol];
    			}
    			int sum = kadanes(temp);
    			res = max(res,sum);
    		}
    	}
    	cout<<res<<"\n";
    }
}
 
int32_t main()
{
    c_p_c();
    return 0;
}