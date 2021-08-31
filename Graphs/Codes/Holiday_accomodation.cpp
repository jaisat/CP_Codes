	#include<bits/stdc++.h>
	#define int long long int 
	using namespace std;
	class Graph{
		int v;
		list<pair<int,int> > *l;
	public:
		Graph(int v){
			this->v = v;
			l = new list<pair<int,int> > [v+1];
		}
		void addEdge(int u,int v,int cost){
			l[u].push_back(make_pair(v,cost));
			l[v].push_back(make_pair(u,cost));
		}

		int dfs_helper(int node,bool *visited,int *count,int &ans){

			// Mark the node Visited
			visited[node] = true;
			count[node] = 1;
			for(auto nbr_pair : l[node]){
				int nbr = nbr_pair.first;
				int wt = nbr_pair.second;
				if(!visited[nbr]){
					count[node] += dfs_helper(nbr,visited,count,ans);
					int nx = count[nbr];
					int ny = v - nx;
					ans += 2 * min(nx,ny) * wt;
				}
			}
			return count[node];
		}

		int dfs(){

			bool *visited = new bool[v+1];
			int  *count   = new int[v+1];

			for(int i = 1;i<=v;i++){
				visited[i] = false;
				count[i] = 0;
			}
			int ans = 0;
			dfs_helper(1,visited,count,ans);
			return ans;
		}

	};
	signed main(){

		int t;
		cin>>t;
		for(int i = 1;i<=t;i++){
			int n,x,y,z;
			cin>>n;
			Graph g(n);
			for(int j = 0;j<n - 1;j++){
				cin>>x>>y>>z;
				g.addEdge(x,y,z);
			}
			cout<<"Case #"<<i<<": "<<g.dfs()<<endl;
		}
		return 0;
	}