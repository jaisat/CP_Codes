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
bool minHeap  = false;
bool compare(int a,int b){
	if(minHeap){
		return a < b;
	}else{
		return a > b;
	}
}
// O(N*LogN) appraoch--->
void buildHeap(vector<int> &arr){
	int n = arr.size();
	for(int i=2;i<n;i++){
		int idx    = i;
		int parent = idx / 2;
		while(idx > 1 and compare(arr[idx],arr[parent])){
			swap(arr[idx],arr[parent]);
			idx = parent;
			parent = idx / 2;
		} 
	}
}
// O(N) Approach--->
void heapify(int idx&arr){
	int left  = idx * 2;
	int right = left + 1;

	int last = arr.size()-1;
	int min_idx = idx;
	if(left <= last and compare(arr[left],arr[idx])){
		min_idx = idx;
	}
	if(right <= last and compare(arr[right],arr[min_idx])){
		min_idx = right;
	}
	if(min_idx != idx){
		swap(arr[min_idx],arr[idx]);
		heapify(min_idx);
	}
}
void buildHeap(vector<int> &arr){
	int n = arr.size();
	for(int i=n/2;i>=0;i--){
		heapify(i,arr);
	}
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
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++) cin >> arr[i];
    buildHeap(arr);
	for(auto x : arr){
		cout<<x<<" ";
	}
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