#include<bits/stdc++.h>
#define int long long int
using namespace std;
// DSU by path compression and Union by rank
class DSU{

	int *parent;
	int *rank;
public:
	DSU(int n){
		parent = new int[n];
		rank   = new int[n];

		for(int i = 0; i < n; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find 
	int find(int i){
		if(parent[i] == -1)
			return i;
		return parent[i] = find(parent[i]);	
	}

	void Unite(int x,int y){

		int s1 = find(x);
		int s2 = find(y);

		if(s1 != s2){

			if(rank[s1] < rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}else{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph{

	int v;
	vector<vector<int> > edgelist;
public:
	Graph(int v){
		this->v = v;
	}
	void addEdge(int x,int y,int w){
		edgelist.push_back({w,x,y});
	}
	int Kruskal_mst(){

		sort(edgelist.begin(),edgelist.end());

		int ans = 0;

		for(auto edge : edgelist){

			DSU s(v);
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if(s.find(x) != s.find(y)){
				s.Unite(x,y);
				ans += w;
			}

		}
		return ans;
	}
};


signed main(){

	int n,m;
	cin>>n>>m;
	Graph g(n);
	for(int i = 0; i < m; i++){
		int x,y,w;
		cin>>x>>y>>w;
		g.addEdge(x-1,y-1,w);
	}

	cout<<g.Kruskal_mst()<<endl;

	return 0;
}