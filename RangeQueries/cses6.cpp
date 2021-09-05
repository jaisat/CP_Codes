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
#define deb(x)          cout << #x << "=" << x << endl
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(x)			x.begin(), x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi arr,seg;
int n;

void buildTree(int s,int e,int idx){
	if(s == e){
		seg[idx] = arr[s];
		return;
	}

	int mid = (s + e) / 2;
	buildTree(s,mid,2*idx);
	buildTree(mid+1,e,2*idx+1);
	seg[idx] = seg[2*idx] + seg[2*idx+1];
	return;
}

int query(int s,int e,int i,int idx){
	if(i < s || i > e){
		return -1;
	}

	if(s == e){
		return seg[idx];
	}

	int mid = (s + e) / 2;
	int L = query(s,mid,i,2*idx);
	if(L != -1){
		return L;
	}
	int R = query(mid+1,e,i,2*idx+1);
	if(R != -1){
		return R;
	}
	return -1;
}


// O(N) worst case if Updation happens from [0,n-1]
void rangeUpdate(int s,int e,int qs,int qe,int idx,int change){
	if(s > qe || e < qs){
		return;
	}	

	if(s == e){
		seg[idx] += change;
		return;
	}
	int mid = (s + e) / 2;
	rangeUpdate(s,mid,qs,qe,2*idx,change);
	rangeUpdate(mid+1,e,qs,qe,2*idx+1,change);
	return;
}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q;
    cin >> n >> q;
    arr.resize(n);
    seg.resize(4*n+1);


    for(int i=0;i<n;i++) cin >> arr[i];
   	
   	buildTree(0,n-1,1);
    while(q--){
    	int type;
    	cin >> type;
    	if(type == 1){
    		int a,b,u;
    		cin >> a >> b >> u;
    		rangeUpdate(0,n-1,a-1,b-1,1,u);
    	}else{
    		int i;
    		cin >> i;
    		cout<<query(0,n-1,i-1,1)<<"\n";
    	}
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