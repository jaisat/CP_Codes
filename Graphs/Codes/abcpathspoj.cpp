#include<bits/stdc++.h>
#define maxn 51
using namespace std;
char mat[maxn][maxn];
bool visited[51][51];
int dp[51][51];
int n,m;
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {0,-1,1,1,-1,0,-1,1};
int dfs_helper(int i,int j,char sr){

	if(i<0 || i>=n || j<0 || j>=n){
		return 0;
	}

   if(dp[i][j]!=0){
   		return dp[i][j];
   }
   visited[i][j] = true;
   int ans = 0;
  for(int k = 0;k<8;k++){
  	int x = i + dx[k];
  	int y = j + dy[k];
  	if(!visited[x][y]){
  		if(mat[x][y] == sr){
  			char nsr = char(mat[x][y] + 1);
  			int sub = dfs_helper(x,y,nsr);
  		
  			ans = max(ans,sub + 1);
  		}
  	}
  }

return dp[i][j] = ans;

}

int dfs(int x,int y){

for(int i = 0;i<n;i++){
	for(int j =0;j<m;j++){
		visited[i][j] = false;
	}
}
int ans = dfs_helper(x,y,'B');
return ans + 1;

}
int main(){
	int h,w;
	cin>>h>>w;
	n = h;
	m = w;
	for(int i = 0;i<maxn;i++){
					for(int j = 0;j<maxn;j++){
						mat[i][j] = '-';
					}
				}
	
	int c = 1;
	while(h != 0 and w!=0){
	   for(int i = 0;i<h;i++){
		  for(int j = 0;j<w;j++){
			 cin>>mat[i][j];
		} 
	}
	
	cin>>h>>w;
	// for(int i = 0;i<n;i++){
	// 	for(int j = 0;j<m;j++){
	// 		cout<<mat[i][j];
	// 	}
	// 		cout<<endl;
	// 	}

	// }
	
	           
				c++;
				for(int i = 0;i<maxn;i++){
					for(int j = 0;j<maxn;j++){
						mat[i][j] = '-';
					}
				}
	
}
	return 0;

}