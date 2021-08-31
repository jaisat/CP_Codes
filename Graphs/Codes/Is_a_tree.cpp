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
	void addEdge(int u,int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	void dfs_helper(int src,bool *visited){
		visited[src] = true;
		for(auto p : l[src]){
			if(!visited[p]){
				dfs_helper(p,visited);
			}
		}
	}
	int dfs(){
		bool *visited = new bool[v+1];
		for(int i = 0;i<=v;i++)
			visited[i] = false;

		int cnt = 0;
		for(int i = 1;i<=v;i++){
			if(!visited[i]){
				dfs_helper(i,visited);
				cnt++;
			}
		}
		return cnt;
	}
};
signed main(){

	int n,m;
	cin>>n>>m;
	Graph g(n);
	for(int i = 0;i<m;i++){
		int v,u;
		cin>>v>>u;
		g.addEdge(v,u);
	}
	//cout<<g.dfs()<<endl;
	if(m == n-1 && g.dfs() == 1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
