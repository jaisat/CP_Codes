#include<bits/stdc++.h>
using namespace std;
char a[51][51];
int dp[51][51];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {0,-1,1,1,-1,0,-1,1};
bool isValid(int i,int j,int n,int m){
	if(i<0 || i>=n || j<0 || j>=m)
		return false;
	return true;
}
int dfs(int i,int j,int n,int m){

	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = 0;
	for(int k = 0;k<8;k++){
		int sx = i + dx[k];
		int sy = j + dy[k];
		if(isValid(sx,sy,n,m) and a[sx][sy] == a[i][j] + 1){
			ans = max(ans,dfs(sx,sy,n,m));
		}
	}
	ans += 1;
	return dp[i][j] = ans;
}
int main(){

	int r,c;
	int t = 0;
	while(1){
		cin>>r>>c;
		if(r == 0 and c == 0)
			break;
		t++;

		for(int i = 0;i<r;i++){
			for(int j = 0;j<c;j++){
				cin>>a[i][j];
			}
		}
		int ans = 0;
		for(int i = 0;i<r;i++){
			for(int j = 0;j<c;j++){
				if(a[i][j] == 'A'){
					memset(dp,-1,sizeof(dp));
					ans = max(ans,dfs(i,j,r,c));
				}
			}
		}
		 cout<<"Case "<<t<<": "<<ans<<endl;
	}
	return 0;
}
