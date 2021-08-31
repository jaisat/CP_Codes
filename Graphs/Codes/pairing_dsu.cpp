#include<bits/stdc++.h>
using namespace std;
class Graph{

	int v;
	list<pair<int,int> > l;
public:
	Graph(int v){
		this->v = v;
	}
	void addEdge(int x,int y){
		l.push_back(make_pair(x,y));
	}


	int Find_set(int i,int parent[]){

		if(parent[i] == -1){
			return i;
		}

		return parent[i] = Find_set(parent[i],parent);
	}

	void Union_set(int x,int y,int parent[],int rank[]){

		int s1 = Find_set(x,parent);
		int s2 = Find_set(y,parent);

		if(s1!=s2){
			if(rank[s1]<rank[s2]){
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}else{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	int pairing(){

		int *parent = new int[v];
		int *rank = new int[v];

		for(int i = 0;i<v;i++){
			parent[i] = -1;
			rank[i] = 1;
		}
		for(auto edge : l){

			int i = edge.first;
			int j = edge.second;

			int s1 = Find_set(i,parent);
			int s2 = Find_set(j,parent);

			Union_set(s1,s2,parent,rank);
		}


		int ans = 0;
		for(int i = 0;i<v;i++){
			ans += v-rank[Find_set(i,parent)];
		}

		delete [] parent;
		delete [] rank;

		return ans/2;
	}
};
int main(){

	int n,m;
	cin>>n>>m;
	Graph g(n);
	while(m--){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	cout<<g.pairing()<<endl;
	return 0;
}