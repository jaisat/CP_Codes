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
 

bool compare(pii p1,pii p2){
	return p1.ff > p2.ff;
}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    w(x){
    	int n,D,F,flag = 0;
    	cin >> n;
    	vector<pair<int,int> > v(n);
    	priority_queue<int> pq;
    	for(int i=0;i<n;i++){
    		int a,b;
    		cin >> a >> b;
    		v[i] = {a,b};
    	}
    	sort(v.begin(),v.end(),compare);

    	cin >> D >> F;
    	for(int i=0;i<n;i++){
    		v[i].ff = D - v[i].ff;
    	}

    	int prev = 0;
    	int x = 0;
    	int ans = 0;
    	while(x < n){
    		if(F >= (v[x].ff-prev)){
    			F = F - (v[x].ff - prev);
    			pq.push(v[x].ss);
    			prev = v[x].ff;
    		}else{
    			if(pq.empty()){
    				flag = 1;
    				break;
    			}

    			F += pq.top();
    			pq.pop();
    			ans += 1;
    			continue;
    		}
    		x++;
    	}

    	if(flag == 1){
    		cout<<-1<<endl;
    		continue;
    	}

    	D = D - v[n-1].ff;
    	if(F >= D){
    		cout<<ans<<endl;
    		continue;
    	}

    	while(F < D){
    		if(pq.empty()){
    			flag = 1;
    			break;
    		}
    		F += pq.top();
    		pq.pop();
    		ans += 1;
    	}
    	if(flag == 1){
    		cout<<-1<<endl;
    		continue;
    	}
    	cout<<ans<<endl;
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