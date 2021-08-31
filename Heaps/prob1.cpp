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
 
#define pci pair<char,int> 
class compfreq{
public:
	bool operator()(pci p1,pci p2){
		return p1.ss < p2.ss;
	}
};
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str;
    int k;
    cin >> str >> k;
    unordered_map<char,int> mp;
    for(auto ch : str){
    	mp[ch]++;
    }
    priority_queue<pci,vector<pci>,compfreq> maxHeap;
    for(auto itr : mp){
    	maxHeap.push(itr);
    }
    queue<pci> queue;
    string ans = "";
    while(!maxHeap.empty()){
    	auto tp = maxHeap.top();
    	maxHeap.pop();

    	ans += tp.ff;
    	tp.ss--; 
    	queue.push(tp);
    	if(queue.size() == k){
    		auto entry = queue.front();
    		queue.pop();
    		if(entry.ss > 0)
    			maxHeap.push(entry);
    	}
    }
    if(ans.length() == str.length()){
    	cout<<ans<<"\n";
    }else{
    	cout<<"NOT POSSIBLE";
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