#include<bits/stdc++.h>
#define int long long int 
#define pii pair<int,int> 
using namespace std;
class Graph{

	int v;
	vector<pii> *l;
public:
	Graph(int v){
		this->v = v;
		l = new vector<pii>[v];
	}
	void addEdge(int x,int y,int w){
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	int Prims(){
		bool *visited = new bool[v]{0};

		priority_queue<pii,vector<pii>,greater<pii> > Q;
		int ans = 0;

		Q.push({0,0});
		while(!Q.empty()){

			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weigth = best.first;

			if(!visited[to]){
				
				visited[to] = 1;
				ans += weigth;

				for(auto x : l[to]){
					if(visited[x.first] == 0){
						Q.push({x.second,x.first});
					}
				}
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
	
	cout<<g.Prims()<<endl;

	return 0;


}