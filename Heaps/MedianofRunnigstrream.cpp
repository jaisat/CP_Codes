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
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    priority_queue<int> leftheap;
    priority_queue<int,vector<int>,greater<int> > rightheap;

    int d;
    cin >> d;
    leftheap.push(d);

    float med;
    cout<<"Median is: "<<d<<endl;

    cin >> d;
    while(d!=-1){

    	if(leftheap.size() > rightheap.size()){
    		if(d < med){
    			rightheap.push(leftheap.top());
    			leftheap.pop();
    			leftheap.push(d);
    		}else{
    			rightheap.push(d);
    		}
    		med = (leftheap.top() + rightheap.top())/2.0;
    	}else if(leftheap.size() == rightheap.size()){
    		if(d < med){
    			leftheap.push(d);
    			med = leftheap.top();
    		}else{
    			rightheap.push(d);
    			med = rightheap.top();
    		}
    	}else{
    		if(d > med){
    			leftheap.push(rightheap.top());
    			rightheap.pop();
    			rightheap.push(d);
    		}else{
    			leftheap.push(d);
    		}
    		med = (leftheap.top() + rightheap.top()) / 2.0;
    	}
    	cout<<"Median is: "<<med<<"\n";
    	cin >> d;
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