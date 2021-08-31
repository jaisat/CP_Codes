#include<bits/stdc++.h>
using namespace std;
int main(){
	  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			mp[x]++;
		}
		long long int ans = 0;
		for(auto key : mp){
			if(mp.find(2 * key.first) != mp.end()){
				ans += mp[key.first] * mp[2 * key.first];
			}
		}
		cout<<ans<<"\n";
		mp.clear();
	}
	return 0;
}