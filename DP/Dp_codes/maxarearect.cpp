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

int Histogram(vector<int> &hist){
	int c = hist.size();
	int i = 0;
	stack<int> s;
	int area;
	int tp;
	int maxar = 0;
	while(i < c){
		if(s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else{
			tp = s.top();
			s.pop();
			area = hist[tp] * (s.empty() ? i : (i - s.top() - 1));
			maxar = max(maxar,area);
		}
	}
	while(!s.empty()){
		tp = s.top();
		s.pop();
		area = hist[tp] * (s.empty() ? i : (i - s.top() - 1));
		maxar = max(maxar,area);
	}
	return maxar;
} 
int maxareareact(vector<vi> &A){
	int n = A.size();
	int m = A[0].size();
	int sub = Histogram(A[0]);
	int maxa = 0;
	maxa = max(sub,maxa);
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(A[i][j])
				A[i][j] += A[i-1][j];
		}
		sub = Histogram(A[i]);
		maxa = max(maxa,sub);
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
    int n,m;
    cin >> n >> m;
    vector<vi> A(n,vi(m));
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin >> A[i][j];

    cout<<maxareareact(A)<<"\n";
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