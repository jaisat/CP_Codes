#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Graph{
	int v;
	list<pair<int,int> > *l;
public:
	Graph(int v){
		this->v = v;
		l = new list<pair<int,int> >[v+1];
	}
	void addEdge(int u,int v,int wt){
		l[u].push_back(make_pair(v,wt));
		l[v].push_back(make_pair(u,wt));
	}

	int dfs_helper(int src,bool *visited,int *dist,int parent){

		visited[src] = true;
		int ans = 0;
		for(auto nbr_pair : l[src]){
			int node = nbr_pair.first;
			int wt = nbr_pair.second;
			if(!visited[node]){
				int sub = dfs_helper(node,visited,dist,parent+wt) + wt;
				ans = max(ans,sub);
			}
			dist[src] = max(parent,ans);
		}

		return ans;
	}

	void dfs(){
		bool *visited = new bool[v+1];
		int *dist = new int[v+1];
		for(int i = 1;i<=v;i++){
			visited[i] = false;
			dist[i] = INT_MIN;
		}
		int parent = 0;
		dfs_helper(1,visited,dist,parent);

		for(int i = 1;i<=v;i++)
			cout<<dist[i]<<" ";
	}
};
signed main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		Graph g(n);
		for(int i = 0;i<n-1;i++){
			int u,v,wt;
			cin>>u>>v>>wt;
			g.addEdge(u,v,wt);
		}
		g.dfs();
		cout<<endl;
	}
	return 0;
}