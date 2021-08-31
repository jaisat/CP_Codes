#include<bits/stdc++.h>
#define n 4
#define pii pair<int,int> 
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool is_valid(int x,int y,int mat[][n]){

	if(x < 0 || x >=n || y < 0 || y >=n || mat[x][y] == 0 )
		return false;
	return true;
}

int min_moves(int mat[][n]){

	int visited[n][n];
	for(int i = 0;i< n; i++){
		for(int j = 0;j < n;j++){
			visited[i][j] = INT_MAX;
		}
	}

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
	//cout<<x<<" "<<y<<endl;
	queue<pii> Q;
	Q.push({x,y});
	visited[x][y] = 0;
	int ans = INT_MAX;
	int flag = 0;
	while(!Q.empty()){

		pii node = Q.front();
		Q.pop();
		 x = node.first;
		 y = node.second;

		if(mat[x][y] == 2){
			return visited[x][y];
		}

		for(int k = 0; k < 4; k ++){
			int i = x + dx[k];
			int j = y + dy[k];
			if(is_valid(i,j,mat) and visited[i][j] == INT_MAX){
				//cout<<i<<" "<<j<<endl;
				Q.push({i,j});
				visited[i][j] = visited[x][y] + 1;
			}
		}
	}
	return ans;
}
int main(){
	 int mat[4][4] = {{ 3 , 3 , 1 , 0 },
                   { 3 , 0 , 3 , 3 },
                   { 2 , 3 , 0 , 3 },
                   { 0 , 3 , 3 , 3 }};

    cout<<min_moves(mat)<<endl;
    return 0;
}