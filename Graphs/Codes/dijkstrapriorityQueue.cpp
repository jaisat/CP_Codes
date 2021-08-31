#include<bits/stdc++.h>
#define pii pair<int,int>
const int mx = 1e5+5;
int dist[mx],par[mx],vis[mx],N,E;
using namespace std;
vector<pii> g[mx];
bool Dijkstra(int src,int dest){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i =1;i<=N;i++)
		dist[i] = INT_MAX;
	pq.push({0,src});
	dist[src] = 0;
	par[src] = -1;
	while(!pq.empty()){
		int val = pq.top().second;
		pq.pop();
		if(val == dest)
			return true;
		vis[val] = 1;
		for(auto nbr : g[val]){
			int w = nbr.second;
			int v = nbr.first;
			if(!vis[v] && dist[v] > dist[val] + w){
				dist[v] = dist[val] + w;
				pq.push({dist[v],v});
				par[v] = val;
			}
		}
	}
	return false;
}
signed main(){
	int u,v,w;
	cin>>N>>E;
	for(int i=0;i<E;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	if(Dijkstra(1,N)){
		vector<int> path;
		int i = N;
		while(i!=-1){
			path.push_back(i);
			i = par[i];
		}
		for(int i =path.size()-1;i>=0;i--)
			cout<<path[i]<<" ";
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}