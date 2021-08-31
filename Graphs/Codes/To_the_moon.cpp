#include<bits/stdc++.h>
#define int long long int 
using namespace std;
template<typename T> 
class Graph{
	map<T,list<T> > l;
public:
	void addEdge(T x,T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	int  dfs_helper(T src,map<T,bool> &visited){
		
		//cout<<src<<" ";
		visited[src] = true;
		int ans = 0;
		for(auto nbr : l[src]){
			if(!visited[nbr]){
				ans += 1 + dfs_helper(nbr,visited);
			}
		}
		return ans;
	}

	int dfs(){
		map<T,bool> visited;
		for(auto node_pair : l){
			T node = node_pair.first;
			visited[node] = false;
		}

		int cnt = 1;
		int ans = 0;
		int k;
		for(auto p : l){
			T node = p.first;
			if(!visited[node]){
				//cout<<"Connected component "<<cnt<<"-->";
				k = 1 + dfs_helper(node,visited);
				cnt++;
				//cout<<k<<endl;
				//cout<<endl;
				ans += k*(k-1)/2;
			}
		}
		return ans;
	}
};
signed main(){
		Graph<int> g;
		int n,p;
		cin>>n>>p;
		for(int i = 0;i<p;i++){
			int x,y;
			cin>>x>>y;
			g.addEdge(x,y);
		}

		int extra = g.dfs();
		//cout<<extra<<endl;
		cout<<n*(n-1)/2 - extra<<endl;
	return 0;
}