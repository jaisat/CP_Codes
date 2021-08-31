#include<bits/stdc++.h>
#define int long long int
using namespace std;

bool dfs_helper(vector<int> graph[],int node,int parent,int* visited,int color){

	visited[node] = color;

	for(auto nbr : graph[node]){

		if(visited[nbr] == 0){
			bool sub = dfs_helper(graph,nbr,node,visited,3-color);
			if(sub == false){
				return false;
			}
		}else if(nbr!=parent and color == visited[nbr]){
			return false;
		}
	}
	return true;

}

bool dfs(vector<int> graph[],int N){

	int visited[N+1] = {0};
	int color = 1;


	for(int i =1;i<=N;i++){
		if(visited[i] == 0){
			bool ans = dfs_helper(graph,i,-1,visited,color);
			if(ans == false){
				return false;
			}
		}
	}
	// for(int i = 0;i<N;i++){
	// 	cout<<"color of "<<i<<"is "<<visited[i]<<endl;
	// }
	return true;
}
signed main(){

	int t;
	cin>>t;
	for(int i = 1;i<=t;i++){
	int N,M;
	cin>>N>>M;
	vector<int> graph[N+1];
	while(M--){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

		if(dfs(graph,N)){
			cout<<"Scenario #"<<i<<":"<<endl<<"No suspicious bugs found!"<<endl;
		}else{
		    cout<<"Scenario #"<<i<<":"<<endl<<"Suspicious bugs found!"<<endl;
		}
	}

	
	return 0;
}