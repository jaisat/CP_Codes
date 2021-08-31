#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> node;
int dfs(int src,vector<int> &visited){

	
	visited[src] = 1;

	int sub = 0;
	for(auto nbr : g[src]){
		if(!visited[nbr]){
			sub += dfs(nbr);
		}
	}
	return node[src] = sub + 1;
}
int main(){

	cout<<dfs(1)<<endl;
	return 0;
}