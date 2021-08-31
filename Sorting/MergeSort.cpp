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
 
void merge(vector<int> &arr,int s,int e){
	int mid = (s + e) / 2;
	int i = s;
	int j = mid+1;
	int k = 0 ;
	vi temp(e - s + 1);
	while(i <= mid and j <= e){
		if(arr[i] > arr[j]){
			temp[k++] = arr[j++];
		}else{
			temp[k++] = arr[i++];
		}
	}

	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= e)
		temp[k++] = arr[j++];

	for(int idx = s; idx <= e; idx++)
		arr[idx] = temp[idx - s];
}

void mergeSort(vector<int>&arr,int s,int e){
	if(s >= e)
		return;
	int mid = (s + e) / 2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e); 
	merge(arr,s,e);
}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vi arr = {1,2,5,9,3,4,6,3,7,9};
    int n = arr.size();
    mergeSort(arr,0,n-1);
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