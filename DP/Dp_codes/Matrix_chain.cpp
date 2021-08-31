#include<bits/stdc++.h>
using namespace std;
int Matrix_chain(vector<int> &A){
	int dp[200][200];
	memset(dp,0,sizeof(dp));
	int n = A.size() - 1;
	for(int i = 1;i<n;i++){
		int r = 0;
		int c = i;
		while(c<n){
			int val = INT_MAX;
			for(int pivot = r;pivot<c;pivot++){
				val = min (val,dp[r][pivot] + dp[pivot+1][c]+A[r]*A[pivot+1]*A[c+1]);
			}
			dp[r][c] = val;
			r++;
			c++;
		}
	}
	return dp[0][n -1];
}
int main(){
	vector<int> A{4,2,3,1,3};
	cout<<Matrix_chain(A)<<endl;
	return 0;
}