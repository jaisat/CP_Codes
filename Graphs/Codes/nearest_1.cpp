// Very Very Important Question for interview pereparation
#include<bits/stdc++.h>
using namespace std;
int maxManHatten(vector<vector<int> > &grid){
	int n = grid.size();
	int result = 0;
	queue<pair<int,int> > q;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(grid[i][j] == 1){
				q.push({i,j});
			}
		}
	}
	q.push({-1,-1});
		set<pair<int,int> > visited;
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		if(p.first == -1 and p.second == -1){
			result++;
			q.push({-1,-1});
			continue;
		}
		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,1,-1};
		for(int k = 0; k < 4; k++){
			int x = p.first + dx[k];
			int y = p.second + dy[k];
			if(visited.count({x,y}) or grid[x][y] == 1)
				continue;
			q.push({x,y});
			visited.insert({x,y});
		}
	}
	return result - 1;
}
int main(){

	return 0;
}