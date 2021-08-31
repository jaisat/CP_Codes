#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int Rod_cutting(int length[],int price[],int N,int n){
	if(n == 0 || N == 0)
		return 0;
	if(dp[n][N]!=0)
		return dp[n][N];
	if(N>=length[n-1]){
		return dp[n][N] = max(price[n-1]+Rod_cutting(length,price,N-length[n-1],n),Rod_cutting(length,price,N,n-1));
	}else{
		return dp[n][N] = Rod_cutting(length,price,N,n-1);
	}
	return dp[n][N];
}
int main(){
	int length[] = {};
	int price[] = {};
	int N = ;
	int n = sizeof(length)/sizeof(int);
	cout<<Rod_cutting(length,price,N,n)<<endl;
	return 0;
}