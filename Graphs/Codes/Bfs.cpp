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
	void bfs(T src){
		queue<T> q;
		map<T,bool> visited;
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto nbr : l[node]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout<<endl;
	}

};
int main(){

	Graph<string> g;
	g.addEdge("A","B");
    g.addEdge("A","C");
	g.addEdge("C","D");	
	g.addEdge("B","D");
	g.addEdge("D","E");

	g.bfs("A");
	return 0;
}