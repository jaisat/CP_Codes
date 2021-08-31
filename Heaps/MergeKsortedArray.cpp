#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
//#define int             long long
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
struct node
{
	int val;
	int row;
	int col;
};
class nodecompare
{
public:
	bool operator()(node n1,node n2){
		return n1.val > n2.val;
	}
	
};

//#define node pair<int,pair<int,int> > 

vector<int> MergeKsortedarray(vector<vector<int> > &arr){

	priority_queue<node,vector<node>,nodecompare > pq_min;
	for(int i=0;i<arr.size();i++){
		pq_min.push({arr[i][0],i,0});
	}
	vector<int> ans;
	while(!pq_min.empty()){
		int val = pq_min.top().val;
		int row = pq_min.top().row;
		int col = pq_min.top().col;

		pq_min.pop();
		ans.push_back(val);

		if(col + 1 < arr[row].size()){
			pq_min.push({arr[row][col+1],row,col+1});
		}
	}
	return ans;
}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<vi> arr = {{2,4,6,8},
    {1,4,5},
    {8,9,10,11},
    {6}
    };
    vector<int> ans = MergeKsortedarray(arr);
    for(auto x : ans){
    	cout<<x<<" ";
    }
    cout<<"\n";

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