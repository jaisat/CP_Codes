#include<bits/stdc++.h>
#define pii pair<int,int> 
using namespace std;

void bfs(int a,int b,int target){

map<pii,int> visited;
queue<pii> q;

bool isSolvable = false;
vector<pii> path;

	q.push({0,0});

	while(!q.empty()){
		pii u = q.front();
		q.pop();

		if(visited[{u.first,u.second}] == 1)
			continue;
		if(u.first > a || u.first < 0 || u.second > b || u.second < 0)
			continue;

		path.push_back({u.first,u.second});
		visited[{u.first,u.second}] = 1;
		
		if(u.first == target || u.second == target){

			isSolvable = true;
			if(u.first == target){
				if(u.second != 0){
					path.push_back({u.first,0});
				}
			}else{
				if(u.second != 0){
					path.push_back({0,u.second});
				}
			}

			int sz = path.size();
			for(int i = 0; i < sz; i++){
				cout<<"("<<path[i].first<<path[i].second<<")"<<endl;
			}
			break;

		}

		q.push({u.first,b});
		q.push({a,u.second});

		for(int tmp = 0; tmp <= max(a,b); tmp++){
			int c = u.first + tmp;
			int d = u.second - tmp;

			if(c == a || d == 0)
				q.push({c,d});

			c = u.first - tmp;
			d = u.second + tmp;

			if(c == 0 || d == b)
				q.push({c,d});
		}

		q.push({a,0});
		q.push({0,b});
	}
	if(!isSolvable)
		cout<<"No Solution"<<endl;

}

int main(){

	int n,m,d;
	cin>>n>>m>>d;

	bfs(n,m,d);

	return 0;
}