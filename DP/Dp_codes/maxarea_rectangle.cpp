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
 
vector<vector<int> > arr;
int n;
int Histogram(vector<int> &temp){
	stack<int> s;
	int tp;
	int area;
	int maxa = 0;
	int i = 0;
	while(i < n){
		if(s.empty() || temp[s.top()] <= temp[i])
			s.push(i++);
		else{
			tp = s.top();
			s.pop();
			area = temp[tp] * (s.empty()? i : (i - s.top() - 1));
			maxa = max(maxa,area);
		}
	}
	while(!s.empty()){
		tp = s.top();
		s.pop();
		area = temp[tp] * (s.empty() ? i : (i - s.top() - 1));
		maxa = max(maxa,area);
	}
	return maxa;
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
   	for(int i=0; i < n;++i)
   		for(int j=0; j < n;j++)
   			cin >> arr[i][j];

   	int sub;
   	int ans = INT_MIN;
   	vector<int> temp(n,0);
   	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			if(arr[i][j])
   			temp[j] = temp[j] + arr[i][j];
   			else 
   				temp[j] = 0;
   		}
   		sub = Histogram(temp);
   		cout<<sub<<" ";
   		ans = max(ans,sub);
   	}
   	cout<<"\n";
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