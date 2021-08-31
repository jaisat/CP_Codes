#include<bits/stdc++.h>
using namespace std;
int color[100005];
int n,m;
class Graph{

	int v;
	list<int> *l;
	public:
		Graph(int v){
			this->v = v;
			l = new list<int>[v+1];
		}
		void addEdge(int x,int y){
			l[x].push_back(y);
			l[y].push_back(x);
		}

		void dfs_helper(int src,bool *visited,int &ans,int count){
			visited[src] = true;
			if(color[src] == 1)
				count++;
			else
				count = 0;
			if(count > m)
				return;
			int flag = 0;
			for(auto nbr : l[src]){
				if(!visited[nbr]){
					flag = 1;
					dfs_helper(nbr,visited,ans,count);
				}
			}
			if(flag == 0)
			 ans += 1;
		}
		int dfs(){

			bool *visited = new bool[v+1];
			for(int i = 1;i<=v;i++)
				visited[i] = false;
			int ans = 0;
			dfs_helper(1,visited,ans,0);

			return ans;
		}
};
int main(){

	
	cin>>n>>m;
	Graph g(n);
	for(int i = 1;i<=n;i++)
		cin>>color[i];

	for(int i = 0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	cout<<g.dfs()<<endl;

	return 0;

}