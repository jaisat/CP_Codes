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

	// Find
	int Find_set(int i,int parent[]){
		if(parent[i]==-1){
			return i;
		}
		// PATH COMPRESSION 
		return parent[i] = Find_set(parent[i],parent);
	}

	void Union_set(int x,int y,int parent[]){

		int s1 = Find_set(x,parent);
		int s2 = Find_set(y,parent);

		if(s1!=s2){
			parent[s1] = s2;
		}
	}

	bool cycle_detection(){

		int *parent = new int[v];
		for(int i = 0;i<v;i++){
			parent[i] = -1;
		}

		for(auto edge : l){
			int i = edge.first;
			int j = edge.second;

			int s1 = Find_set(i,parent);
			int s2 = Find_set(j,parent);

			if(s1!=s2){
				Union_set(i,j,parent);
			}else{
				return true;
			}

		}
		delete [] parent;
		return false;
	}
};
int main(){

	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	//g.addEdge(3,0);

	if(g.cycle_detection()){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}