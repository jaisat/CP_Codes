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

	int dfs_helper(T src,map<T,bool> &visited,map<T,int> &count){
		
		cout<<src<<" ";
		visited[src] = true;
		count[src] = 1;
		for(auto nbr : l[src]){
			if(!visited[nbr]){
			 	count[src] += dfs_helper(nbr,visited,count);
			}
		}
		return count[src];
	}

	void dfs(){
		map<T,bool> visited;
		map<T,int> count;
		for(auto node_pair : l){
			T node = node_pair.first;
			visited[node] = false;
			count[node] = 0;
		} 

		int cnt = 1;
		for(auto p : l){
			T node = p.first;
			if(!visited[node]){
				cout<<"Connected component "<<cnt<<"-->";
				int s = dfs_helper(node,visited,count);
				cout<<"size"<<s<<endl;
				cnt++;
				cout<<endl;
			}
		}	
	}
};
int main(){
		Graph<int> g;
// 	g.addEdge(0,1);
// 	g.addEdge(1,2);
// 	g.addEdge(2,3);
// //	g.addEdge(3,4);
// //	g.addEdge(4,5);
// 	g.addEdge(0,3);
// 	g.addEdge(0,4);

// 	g.addEdge(5,6);
// 	g.addEdge(6,7);
 //	g.addEdge(8,8);
	g.addEdge(0,1);g.addEdge(2,3);g.addEdge(0,4);g.addEdge(8,8);
	g.dfs();
	return 0;
}