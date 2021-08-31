#include<bits/stdc++.h>
#define n 3
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool is_valid(int i,int j,int mat[][n]){

	if(i < 0 || j < 0 || i >= n || j >= n || mat[i][j] == 0)
		return false;
	return true;

}
int dfs_util(int i,int j,int mat[][n],bool visited[][n],int length){

	if(mat[i][j] == 2){
		return length;
	}

	visited[i][j] = true;
	int ans = INT_MAX;
	for(int k = 0;k < 4;k++){
		int x = dx[k] + i;
		int y = dy[k] + j;
 		if(is_valid(x,y,mat)  and (mat[x][y] == 3 or mat[x][y] == 2) and visited[x][y] == false){
 			int op = dfs_util(x,y,mat,visited,length+1);
 			ans = min(ans,op);
 		}
	}
	return ans;
}
int dfs(int mat[][n]){
	bool visited[n][n] = {0};

	int i,j;
    int x,y;
	for(i = 0;i < n; i++){
		for(j = 0;j < n;j++){
			if(mat[i][j] == 1){
				x = i;
                y = j;
                break;
			}	
		}
	}

   
 
	int ans = dfs_util(x,y,mat,visited,0);
	return ans;
}
int main(){

				int mat[3][3] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};
	cout<<dfs(mat)<<endl;
	return 0;
}