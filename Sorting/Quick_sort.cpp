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

int partition(vector<int> &arr,int s,int e){
		int i = s - 1;
		int pivot = arr[e];
		for(int j = s; j <= e - 1; j++){
			if(arr[j] <= pivot){
				i++;
				swap(arr[i],arr[j]);
			}
		}
		swap(arr[e],arr[i+1]);
		return i+1;
}

void QuickSort(vector<int> &arr,int s,int e){
	if(s >= e){
		return;
	}
	int p = partition(arr,s,e);
	QuickSort(arr,s,p-1);
	QuickSort(arr,p+1,e);
}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vi arr = {1,5,3,4,7,9,5};
    int n = arr.size();
    QuickSort(arr,0,n-1);
    for(auto x : arr)
    	cout<<x<<" ";
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