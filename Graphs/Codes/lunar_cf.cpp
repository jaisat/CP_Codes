#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> vis;
int n,m;
void bfs(int src){
	priority_queue<int,greater<int>,vector<int> > pq;
	pq.push(src);
	vis[src] = 1;
	while(!pq){
		int node = pq.top();
		cout<<node<<" ";
		pq.pop();
		for(auto x : g[node]){
			if(!vis[x])
				pq.push(x);
		}

	}
}
int main(){
	cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
	while(m--){
		int u,v;
        cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1;i<g.size();i++){
		sort(g[i].begin(),g[i].end());
	}
	for(int i = 1;i<g.size();i++){
		for(auto x : g[i])
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;

}