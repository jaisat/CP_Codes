#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > l;
public:
	void addEdge(T x, T y){
		l[x].push_back(y);
	}

	void dfs_helper(T src, T dest,int &cnt){

		if(src == dest){
			cnt++;
		}
		for(auto nbr : l[src]){

			dfs_helper(nbr,dest,cnt);
		}
	}
	int dfs(T src, T dest){
			map<T,bool> visited;
			for(auto x : l){
				T node = x.first;
				visited[node] = false;
			}
			int cnt = 0;
			dfs_helper(src,dest,cnt);

			return cnt;
	}

};

int main(){

		Graph<char> g;
		g.addEdge('A','B');
		g.addEdge('A','E');
		g.addEdge('A','C');
		g.addEdge('B','E');
		g.addEdge('B','D');
		g.addEdge('C','E');
		g.addEdge('D','C');

		cout<<g.dfs('A','C')<<endl;
		return 0;

}