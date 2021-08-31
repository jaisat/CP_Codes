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
	void addEdge(int x,int y){
		l[x].push_back(y);
	}

	void bfs(){

		int *indegree = new int[v];
		for(int i = 0;i<v;i++){
			indegree[i] = 0;
		}

		for(int i = 0;i<v;i++){
			for(auto x : l[i]){
				indegree[x]++;
			}
		}
		queue<int> q;
		for(int i = 0;i<v;i++){
			if(indegree[i] == 0){
				q.push(i);
			}
		}

		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(auto x : l[node]){
				indegree[x]--;
				if(indegree[x] == 0){
					q.push(x);
				}
			}
		}
	}
};
int main(){
	Graph g(n);


	return 0;
}