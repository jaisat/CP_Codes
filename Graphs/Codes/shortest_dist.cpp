#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > l;
public:
	void addEdge(T x,T y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void bfs_shortestDist(T src){

		map<T,int> dist;
		queue<T> q;
		for(auto node_pair : l){
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}
		dist[src] = 0;
		q.push(src);
		while(!q.empty()){
			T node = q.front();
			q.pop();
			
			for(auto nbr : l[node]){
				if(dist[nbr] == INT_MAX){
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
				}
			}	
		}
		
		// Print the distance---->

		for(auto node_pair : l){
			T node = node_pair.first;
			int d = dist[node];
			cout<<"Distace of node "<<node<<" from source the source is => "<<d<<endl;
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

	g.bfs_shortestDist(0);

	return 0;
}