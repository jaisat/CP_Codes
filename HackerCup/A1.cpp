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
 
int find(int i,vi &parent){
	if(i  == parent[i])
		return i;
	return parent[i] = find(parent[i],parent);
}

void Union_(int a,int b,vi &parent){

	int s1 = find(a,parent);
	int s2 = find(b,parent);


	if(s1 != s2){
		parent[s1] = s2;
	}
}

int bfs(int src,int dest,vector<int> g[27]){

	queue<pair<int,int>> Q;
	Q.push({src,0});
	vector<int> visited(27);

	while(!Q.empty()){
		auto node = Q.front();
		Q.pop();


		int par  = node.first;
		visited[par] = 1;
		int dist = node.second;
		if(par == dest){
			return dist;
		}

		for(auto ch : g[par]){
			if(!visited[ch]){
				Q.push({ch,dist+1});
			}
		}
	}

	return INT_MAX;

}
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for(int t1 = 1;t1<=t;t1++){

    	vector<int> parent(27);
    	for(int i=0;i<=26;i++) 
    		parent[i] = i;



    	//set<pair<char,char> > visited;
    	string s;
    	cin >> s;
    	int k;
    	cin >> k;
    	vector<int> g[27];
    	
    	for(int i=0;i<k;i++){
    		char a1,b1;
    		cin >> a1 >> b1;
    		int a1_ = (int) (a1 - 65);
    		int b1_ = (int) (b1 - 65);
    	    /*Union_(a1_,b1_,parent);*/
    	    g[a1_].pb(b1_);

    	}

    	int ans = INT_MAX;
    	for(int i=0;i<26;i++){
    		int present = i;
    		int sub = 0;
    		int flag = 1;
    		for(int j = 0;j < s.size();j++){
    			int curr = (int)(s[j] - 65);
    			if(curr == present){
    				continue;
    			}

    		/*	if(find(curr,parent) != find(present,parent)){
    				flag = 0;
    				break;
    			}*/

    			int dist = bfs(curr,present,g);
    			if(dist == INT_MAX){
    				flag = 0;
    				break;
    			}

    			sub += dist;
    		}

    		if(flag){
    			ans = min(ans,sub);
    		}
    	}

    	if(ans == INT_MAX)
    		cout<<"Case #"<<t1<<": "<<-1<<"\n";
    	else
			cout<<"Case #"<<t1<<": "<<ans<<"\n";

    }
}
 
int32_t main()
{
    clock_t begin = clock();
    c_p_c();
/*	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif */
    return 0;
}