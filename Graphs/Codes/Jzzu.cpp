	#include<bits/stdc++.h>
	#define int long long int
	#define pii pair<int,int> 
	#define piii pair<int,pair<int,int> > 
	using namespace std;
	#define mx 100005
	#define inf 1e15+5
    int n;
	vector<pair<pii,int> > g[mx];
	int dist[mx];
	int vis[mx]; 
	void Dijkstra(int src,int &k){
		priority_queue<piii,vector<piii>,greater<piii> > pq;
		for(int i = 1;i<=n;i++)
            dist[i] = inf;
		pq.push({0,{src,0}});
		dist[src] = 0;
		vis[src] = 1;
		while(!pq.empty()){
			int val = pq.top().second.first;
			int f =   pq.top().second.second;
			pq.pop();
			if(f)
				k--;
			vis[val] = 1;
			for(auto nbr : g[val]){
				int nb = nbr.first.first;
				int w =  nbr.first.second;
				int t =  nbr.second;
				if(!vis[nb] and dist[nb] > dist[val] + w){
				
					dist[nb] = dist[val] + w;
					pq.push({dist[nb],{nb,t}});
				}
			}
		}
	}
	signed main(){
		int m,k;
		cin>>n>>m>>k;
		while(m--){
			int u,v,x;
			cin>>u>>v>>x;
			g[u].push_back({{v,x},0});
			g[v].push_back({{u,x},0});
		}
		for(int i=0;i<k;i++){
			int st,y;
			cin>>st>>y;
			g[1].push_back({{st,y},1});
			g[st].push_back({{1,y},1});
				
		}
		Dijkstra(1,k);
		cout<<k<<endl;
		return 0;
	}