#include<bits/stdc++.h>
using namespace std;
int minimum;
int dp[10000][10000];
void min_subdiff(int a[],int sum,int n,int arr_sum){
	if(sum == 0){
		dp[n][sum] = 1;
		return;
	}
	if(n == 0){
		dp[n][sum] = 0;
		return;
	}
	if(dp[n][sum] != -1)
		return;
	minimum = min(minimum,abs(arr_sum - 2* sum));
	dp[n][sum] = 1;
	if(a[n-1]<=sum){
		min_subdiff(a,sum-a[n-1],n-1,arr_sum);
	}
	min_subdiff(a,sum,n-1,arr_sum);
	return;
}
int min_subdiff_iterative(int a[],int sum,int n){
	for(int i = 0;i<=n;i++){
		dp[i][0] = 1;
	}
	for(int i = 1;i<=sum;i++){
		dp[0][i] = 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=sum;j++){
			if(a[i-1]<=j){
				dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
			}else{
				dp[i][j] = d[i-1][j];
			}
		}
	}
	vector<int> v;
	for(int i = 0;i<=sum/2;i++){
		if(d[n][i] == 1)
			v.push_back(i);
	}
	int minimum = INT_MIN;
	for(auto x : v){
		minimum = min(minimum,sum-2*i);
	}
	return minimum;
}
int main(){
   // memset(dp,-1,sizeof(dp));
	int a[] = {1,4};
    int sum = 0;
	int n  =sizeof(a)/sizeof(int);
	for(int i = 0;i<n;i++){
		sum += a[i];
	}
 //     minimum = sum;
	// min_subdiff(a,sum,n,sum);
	// cout<<minimum<<endl;
	cout<<min_subdiff_iterative(a,sum,n);
	return 0;
}