#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,pair<int,int> > 
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
 

int max_(int a,int b){
	if(a > b)
		return a;
	else return b;
}
/*int min_(int a ,int b){
	return a > b ? b : a;
}*/
void findSmallestRange(vector<vector<int> > &arr,int k){
	priority_queue<pii,vector<pii>,greater<pii> > minHeap;
	int maxVal = INT_MIN;
	int minVal;
	for(int i = 0;i<k;i++){
		minHeap.push({arr[i][0],{i,0}});
		maxVal = max_(arr[i][0],maxVal);
	}
	int min,max;
	int range = INT_MAX;
	while(1){	
		/*if(flag)
			break;*/

		pii root = minHeap.top();
		minHeap.pop();
		minVal  = root.ff;
		//cout<<minVal<<" "<<maxVal<<" "<<range<<endl;
		int row = root.ss.ff;
		int col = root.ss.ss;
		if(range > (maxVal - minVal)){
			min = minVal;
			max = maxVal;
			range = maxVal- minVal;
		}
		if(col + 1 >= arr[row].size()){
			break;
		}else{
			minHeap.push({arr[row][col+1],{row,col+1}});
		}	
		maxVal = max_(maxVal,arr[row][col+1]);
	}
	cout<<"["<<min<<","<<max<<"]"<<"\n";
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
         vector<vector<int> > arr = {
        { 4,10,15,24,26},
        { 0,9,12,20},
        { 5,18,22,30}
    };
  	int k = arr.size();
  	findSmallestRange(arr,k);
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