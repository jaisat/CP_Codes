#include<bits/stdc++.h>
using namespace std;
// O(1) Memory space
int max_subarray(int a[],int n){
	int sum=0,max_so_far=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum<0)
			sum=0;
		max_so_far=max(max_so_far,sum);
	}
	return max_so_far;

}
// O(N) Memory Sppace 
int max_subarrayDP(int a[],int n){
	int dp[100]={0};
	dp[0]=a[0]>0?a[0]:0;
	int max_so_far=dp[0];
	for(int i=1;i<n;i++){
		dp[i]=dp[i-1]+a[i];
		if(dp[i]<0)
			dp[i]=0;
		max_so_far = max(max_so_far,dp[i]);
	}
return max_so_far;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
			#ifndef ONLINE_JUDGE
    		freopen("input1.txt", "r", stdin);
    		freopen("output1.txt", "w", stdout);
			#endif
	int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
	int n = sizeof(arr)/sizeof(int);
	cout<<max_subarray(arr,n)<<endl<<max_subarrayDP(arr,n);
	return 0;
}