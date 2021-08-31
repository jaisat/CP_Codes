#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int rod_cutting(int price[],int n){
	if(n == 0)
		return 0;
	if(dp[n]!=0)
		return dp[n];
	int ma = INT_MIN;
	for(int i = 0;i<n;i++){
		int sub = rod_cutting(price,n-i-1)+price[i];
		ma = max(ma,sub);
	}
	return dp[n] = ma;
}
int main(){
	int n;
	int price[] ={1, 5, 8, 9, 10, 17, 17, 20};
    n = sizeof(price)/sizeof(int);
	cout<<rod_cutting(price,n)<<endl;
	return 0;
}