#include<bits/stdc++.h>
using namespace std;
vector<int> g[101];
int in[101],low[101],vis[101];
int timer;
int dfs(int node,int par){
	vis[node] = 1;
	in[node] = low[node] = timer;
	timer++;

	for(auto child : g[node]){
		if(child == par) continue;
		if(vis[child] == 1){
			low[node] = min(low[node],low[child]);

		}else{
			dfs(child,node);

			if(in[node] < low[child])
				cout<<node<<"-"<<child<<"is a bridge"<"\n";
			low[node] = min(low[node],low[child]);	
		}
	}

}
int main(){
	int n,m,x,y;
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,-1);
	return 0;
}