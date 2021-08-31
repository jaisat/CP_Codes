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

bool minHeap = false;
bool compare(int a,int b){
	if(minHeap){
		return a < b;
	}
	else
		return a > b;
}
void heapify(vector<int> &v,int idx,int size){
	int left  = 2 * idx;
	int right = left + 1;

	int min_idx = idx;
	if(left < size and compare(v[left],v[idx])){
		min_idx = left;
	}
	if(right < size and compare(v[right],v[min_idx])){
		min_idx = right;
	}
	if(min_idx != idx){
		swap(v[min_idx],v[idx]);
		heapify(v,min_idx,size);
	}
}
void buildHeap(vector<int> &v){
	for(int i=(v.size()-1)/2;i>=1;i--){
		heapify(v,i,v.size());
	}
}

void Heapsort(vector<int>&v){
	buildHeap(v);
	int n = v.size();
	while(n > 1){
		swap(v[1],v[n-1]);
		n--;
		heapify(v,1,n);
	}
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> v;
    v.push_back(-1);
    int n;
    cin >> n;
    int temp;
    for(int i=1;i<=n;i++){
    	cin >> temp;
    	v.push_back(temp);
    }
   	Heapsort(v);
   	for(int i=1;i<=n;i++)
   		cout<<v[i]<<" ";
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