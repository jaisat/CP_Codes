#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
int in[100001],low[100001],vis[100001],timer;
bool isBridge;
vector<pair<int,int> > edgeList;
void dfs(int node,int par){
	vis[node] = 1;
	in[node] = low[node] = timer++;
	for(auto child : g[node]){
		if(child == par) continue;
		if(vis[child]){
				low[node] = min(low[node],in[child]);
				if(in[child] < in[node])
					edgeList.push_back({node,child});	
		}else{
			dfs(child,node);

			if(low[child] > in[node]){
				isBridge = true;
				return;
			}
			edgeList.push_back({node,child});
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
	if(isBridge){
		cout<<0<<endl;
	}else{
		for(auto e : edgeList){
			cout<<e.first<<" "<<e.second<<endl;
		}
	}
	return 0;
} 