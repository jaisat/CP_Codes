#include<bits/stdc++.h>
using namespace std;
int MaxSum(vector<int> &v,int k){
	int n = v.size();
	unordered_map<int,int> mp;
	int currsum = 0;
	int cnt = 0;
	for(int i=0;i<n;i++){
		currsum += v[i];
		if(currsum == k)
			cnt++;
		if(mp.find(currsum - k)!=mp.end()){
			cnt += mp[currsum-k];
		}
		mp[currsum]++;

	}
	return cnt;

}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,k;
	cin>>n>>k;
	vector<int> v(n,0);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<MaxSum(v,k)<<endl;
	return 0;
}