#include<bits/stdc++.h>
#define mx 100001
using namespace std;
vector<int> g[mx];
int vis[mx],in[mx],low[mx];
int timer;
vector<int> cut;
int cutV;
void Is_cutvertex(int node){
	cutV++;
	cut.push_back(node);
}
void dfs(int node,int par = -1){
	vis[node] = 1;
	in[node] = low[node] = timer++;
	int childrens = 0;
	for(auto nbr : g[node]){
			if(nbr == par) 
				continue;
			if(vis[nbr]){
				low[node] = min(low[node],in[nbr]);
			}else{
				dfs(nbr,node);
				low[node] = min(low[node],low[nbr]);
				if(low[nbr] >= in[node] and par!=-1)
					Is_cutvertex(node);
				childrens++;
			}
	}
	if(par == -1 and childrens > 1)
		Is_cutvertex(node);
}
int main(){

	int n,m;
	cin>>n>>m;
	
	while(m--){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	cout<<"No of Cut Vertices = "<<cutV<<endl;
	for(auto x : cut){
		cout<<x<<" ";
	}
	cout<<"\n";

	return 0;
}