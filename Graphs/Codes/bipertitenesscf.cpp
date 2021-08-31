#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Graph{
	int v;
	list<int> *l;
public:
	Graph(int v){
		this->v = v;
		l = new list<int>[v+1];
	}
	void addEdge(int v,int u){
		l[v].push_back(u);
		l[u].push_back(v);
	}
	void dfs_helper(int src,int *visited,int color){

		visited[src] = color;
		for(auto nbr : l[src]){
			if(visited[nbr] == 0)
			dfs_helper(nbr,visited,3-color);
		}
	}
	int dfs(){
		int *visited = new int[v+1];
		for(int i =1;i<=v;i++){
			visited[i] = 0;
		}
		int color = 1;
		dfs_helper(1,visited,color);
		int cnt = 0;
		for(int i = 1;i<=v;i++){
			if(visited[i] == 1)
				cnt++;
		}
		return cnt;
	}
	
};
signed main(){
	int n;
	cin>>n;
	Graph g(n);
	for(int i = 0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	int l = g.dfs();
	int r = n - l;
	cout<<l*r-(n-1)<<endl;
	return 0;
}