#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
// solution in O(K*N^2)
int Egg_droping(int k,int n){
if(n == 1 || n == 0)
	return n;
if(k == 1)
	return n;


if(dp[k][n] != 0)
	return dp[k][n];
int ans = INT_MAX;
for(int i = 1; i <= n; i++){
 	int op1 = Egg_droping(k - 1,i - 1);
 	int op2 = Egg_droping(k,n - i);
 	int attempt = 1 + max(op1,op2);
 	ans = min(ans,attempt);
}
return dp[k][n] = ans;

}

// solution in O(k*N*log(N))

int Egg_droping_optimized(int k,int n){
	if(n == 1 || n == 0)
		return n;
	if(k == 1)
		return n;
	if(dp[k][n] != 0)
		return dp[k][n];

	int ans = INT_MAX;
	int s = 1;
	int e = n;
	int temp = 0;
	while(s<=e){

		int mid = (s+e)/2;
		int left = Egg_droping_optimized(k-1,mid -1);
		int right = Egg_droping_optimized(k,n - mid);
		temp = 1 + max(left,right);
		if(left < right){
			s = mid + 1;
		}else{
			e = mid - 1;
		}
		ans = min(ans,temp);
	}
	return dp[k][n] = ans;
}

int main(){

	int k,n;
	cin>>k>>n;

	cout<<Egg_droping_optimized(k,n)<<endl;
	return 0;



}