#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > l;
	public:
		void addEdge(T x,T y){
			l[x].push_back(y);
		}

void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering){

	visited[src] = true;
	for(auto nbr : l[src]){
		if(!visited[nbr]){
			dfs_helper(nbr,visited,ordering);
		}
	}
	ordering.push_front(src);
	return;
}

void dfs(){
	map<T,bool> visited;
	list<T> ordering;
	for(auto p : l){
		T node = p.first;
		visited[node] = false;
	}

	for(auto node_pair : l){
		T node = node_pair.first;
		if(!visited[node]){
			dfs_helper(node,visited,ordering);
		}
	}

	for(auto x : ordering){
		cout<<x<<" ";
	}
}

};
int main(){
			Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(0,3);

	g.dfs();
	return 0;
}
