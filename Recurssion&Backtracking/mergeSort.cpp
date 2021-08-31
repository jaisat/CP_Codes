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

void merge(int *a,int s,int e){
	int mid = (s+e)/2;

	int i = s;
	int j = mid + 1;
	int k = s;
	int temp[100];
	while(i <= mid and j <= e){
		if(a[i] < a[j]){
			temp[k++] = a[i++];
		}else{
			temp[k++] = a[j++];
		}
	}
	while(i <= mid){
		temp[k++] = a[i++];
	}
	while(j <= e){
		temp[k++] = a[j++];
	}
	for(int i=s;i<=e;i++){
		a[i] = temp[i];
	}

}
void mergeSort(int a[],int s,int e){
	if(s>=e){
		return;
	}
	int mid = (s+e)/2;
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);
	merge(a,s,e);
	return;
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
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    mergeSort(a,0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
 
int32_t main()
{
    c_p_c();
    return 0;
}