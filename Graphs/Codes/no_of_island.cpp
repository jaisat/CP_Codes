#include<bits/stdc++.h>
#define n 5
using namespace std;
int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {-1,1,-1,0,1,-1,0,1};
bool is_safe(int x,int y,int mat[][n],int visited[][n]){

	if(x < 0 || x >=n || y < 0 || y >=n || mat[x][y] == 0 || visited[x][y])
        return false;
	return true;
}
void dfs(int mat[][n],int visited[][n],int i,int j){
	visited[i][j] = true;

	for(int k = 0; k < 8;k++){
		int x = i + dx[k];
		int y = j + dy[k];
		if(is_safe(x,y,mat,visited)){
			dfs(mat,visited,x,y);
		}
	}
}
int find_island(int mat[][n]){
	int visited[n][n];
    memset(visited,0,sizeof(visited));
	

	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j] and mat[i][j]){
				dfs(mat,visited,i,j);
				count++;
			}
		}
	}
	return count;
}
int main(){

	int mat[5][5] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};
	cout<<find_island(mat)<<endl;
	return 0;
}