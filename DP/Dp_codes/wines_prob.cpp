#include<bits/stdc++.h>
using namespace std;
int profit(int wines[],int i,int j,int y,int dp[][100]){
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	int op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
	int op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);

	return dp[i][j] = max(op1,op2);
}
int main(){
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
   			freopen("output1.txt", "w", stdout);
			#endif	
	int dp[100][100]={0};
	int wines[] = {2,3,5};
	int n = sizeof(wines)/sizeof(int);
	int y =1;
	cout<<profit(wines,0,n-1,y,dp)<<endl;
	return 0;
}