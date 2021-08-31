#include<bits/stdc++.h>
#define pii pair<int,int> 
const int mx = 1e5+5;
using namespace std;
vector<pii> g[mx];
int dist[mx],par[mx],vis[mx],N,E;
bool Dijkstra(int src,int dest){
	set<pii> s;
	for(int i=1;i<=N;i++)
		dist[i] = INT_MAX;
	s.insert({0,src});
	dist[src] = 0;
	par[src] = -1;

	while(!s.empty()){
		auto p = *(s.begin());
		int val = p.second;
		int wt  = p.first;
		if(val == dest)
			return true;
		vis[val] = 1;
		s.erase(s.begin());
		for(auto nbr : g[val]){
			int w = nbr.second;
			int v = nbr.first;
			if(!vis[v] && dist[v] > dist[val] + w ){

				auto f = s.find({dist[v],v});
				if(f!=s.end()){
					s.erase(f);
				}
				dist[v] = wt + w;
				s.insert({dist[v],v});
				par[v] = val;
			}
		}
	}
	return false;
}

using namespace std;
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