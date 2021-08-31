#include<bits/stdc++.h>
using namespace std;
class Graph{
	int v;
	list<int> *l;
public:
	Graph(int v){
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x,int y,bool bidr = true){
		l[x].push_back(y);
		if(bidr){
			l[y].push_back(x);
		}
	}
	bool cycle_helpr(int src,bool* visited,int parent){
		visited[src] = true;
		for(auto nbr : l[src]){
			if(!visited[nbr]){
				bool f_cycle = cycle_helpr(nbr,visited,src);
				if(f_cycle){
					return true;
				}
			}else if(nbr!=parent){
				return true;
			}
		}
		return false;
	}
	bool cotain_cycle(){
		bool *visited = new bool[v];
		for(int i = 0;i<v;i++)
			visited[i] = false;
		for(int i = 0;i<v;i++){
			if(!visited[i]){
				bool found_cycle = cycle_helpr(i,visited,-1);
				if(found_cycle){
					return true;
				}
			}
		}
		return false;
	}
};
int main(){
	Graph g(8);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	//g.addEdge(4,0);
	g.addEdge(5,6);
	g.addEdge(6,7);
	//g.addEdge(7,5);

	if(g.cotain_cycle()){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}