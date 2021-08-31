#include<bits/stdc++.h>
using namespace std;
class Graph{
	int v;
	list<int> *l;
public:
	Graph(int v){
		this->v = v;
		l = new list<int> [v];
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void k_cores(int k){
		bool *visited = new bool[v];
		int *indegree = new int[v];
		for(int i = 0;i<v;i++)
			indegree[i] = 0;
		for(int i = 0;i<v;i++){
				indegree[i] = l[i].size();
		}
		queue<int> q;
		for(int i =0;i<v;i++){
			if(indegree[i] < k){
				q.push(i);
			}
		}

		while(!q.empty()){
			int node = q.front();
			q.pop();


			for(auto x : l[node]){
				indegree[x]--;
				if(indegree[x] < k){
					indegree[node]--;
					q.push(x);
				}
			}
		}

		// for(int i = 0;i<v;i++){
		// 	if(indegree[i]>=k)
		// 		cout<<i<<" ";
		// }
		for(int i = 0 ;i < v; i++)
			cout<<indegree[i]<<" ";

	}
};
int main(){
	 int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.k_cores(k);
    cout<<endl;
    return 0;

}