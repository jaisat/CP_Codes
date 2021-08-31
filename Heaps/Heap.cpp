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
 
class Heap{
	vector<int> v;
	bool minHeap;
	bool compare(int a,int b){
		if(minHeap){
			return a < b;
		}else{
			return a > b;
		}
	}
	void heapify(int idx){
		int left  = 2*idx;
		int right = left + 1;

		int min_idx = idx;
		int last = v.size();

		if(left < last and compare(v[left],v[idx])){
			min_idx = left;
		}
		if(right < last and compare(v[right],v[min_idx])){
			min_idx = right;
		}
		if(min_idx != idx){
			swap(v[idx],v[min_idx]);
			heapify(min_idx);
		}
	}
public:
	Heap(int deafault_size = 10,bool type = true){
		v.reserve(deafault_size);
		v.push_back(-1);
		minHeap = type;
	}
	void push(int d){
		v.push_back(d);
		int idx = v.size()-1;
		int parent = idx / 2;
		while(idx > 1 and compare(v[idx],v[parent])){
			swap(v[idx],v[parent]);
			idx = parent;
			parent = idx / 2;
		}
	}
	int top(){
		return v[1];
	}
	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back();
		heapify(1);
	}
	bool empty(){
		return v.size() == 1;
	}
}; 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Heap h(10,false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
    	int no;
    	cin >> no;
    	h.push(no);
    }
    while(!h.empty()){
    	cout<<h.top()<<" ";
    	h.pop();
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